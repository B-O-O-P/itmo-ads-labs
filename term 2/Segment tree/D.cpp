#include <iostream>
#include <vector>

using namespace std;

int getMiddle(int l, int r) {
    return l + (r - l) / 2;
}


struct Node {
    int number;
    int segments;
    int set;
    int l;
    int r;
    bool up;

    Node() {
        number = 1;
        segments = 1;
        set = 0;
        up = false;
        l = 0;
        r = 0;
    }

    Node(int n, int seg, int s, int left, int right, bool u) {
        number = n;
        segments = seg;
        set = s;
        l = left;
        r = right;
        up = u;
    }
};

vector <Node> t;
vector<char> color;
vector<int> cord;
vector<int> delta;
int n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = Node(0, 0, 0, tl, tr, false);
    } else {
        int tm = getMiddle(tl, tr);
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = Node(0, 0, 0, tl, tr, false);
    }
}

void push(int v) {
    if (!t[v].up)
        return;

    t[v].number = t[v].set * (t[v].r - t[v].l + 1);
    t[v].segments = 1 * t[v].set;
    t[v].up = false;

    if (t[v].l == t[v].r)
        return;

    t[v * 2].set = t[v].set;
    t[v * 2 + 1].set = t[v].set;

    t[v * 2].up = true;
    t[v * 2 + 1].up = true;
}

bool leftisblack(int v) {
    push(v);

    if (t[v].l == t[v].r)
        return t[v].number == 1;

    return leftisblack(v * 2);
}

bool rightisblack(int v) {
    push(v);

    if (t[v].l == t[v].r)
        return t[v].number == 1;

    return rightisblack(v * 2 + 1);
}

void update(int v, int value, int l, int r) {
    if (t[v].r < l || t[v].l > r)
        return;

    if (t[v].r <= r && t[v].l >= l) {
        push(v);
        t[v].set = value;
        t[v].up = true;
        return;
    }

    push(v);
    update(v * 2, value, l, r);
    update(v * 2 + 1, value, l, r);

    bool left = rightisblack(v * 2);
    bool right = leftisblack(v * 2 + 1);

    t[v].number = t[v * 2].number + t[v * 2 + 1].number;
    t[v].segments = t[v * 2 + 1].segments + t[v * 2].segments;

    if (left && right) {
        t[v].segments--;
    }
}

int main() {
    freopen("painter.in", "r", stdin);
    freopen("painter.out", "w", stdout);

    scanf("%d", &n);
    color.resize((unsigned) n);
    cord.resize((unsigned) n);
    delta.resize((unsigned) n);

    int maxdelta = 0;
    int del;
    int maxcord = INT32_MIN;
    int mincord = INT32_MAX;

    for (int i = 0; i < n; i++) {
        scanf("\n%c %d %d", &color[i], &cord[i], &delta[i]);

        if (delta[i] > 0) delta[i]--;
        else delta[i]++;

        del = cord[i] + delta[i];
        if (del > maxcord) {
            maxcord = del;
        }

        if (maxdelta > cord[i]) {
            maxdelta = cord[i];
        }
    }

    int length;
    if (maxdelta < 0) {
        length = maxcord - maxdelta + 1;
    } else {
        length = maxcord + 1;
    }

    t.resize((unsigned) (4 * length));
    build(1, 0, length);
    for (int i = 0; i < n; i++) {
        if (color[i] == 'W') {
            update(1, 0, cord[i] - maxdelta, cord[i] + delta[i] - maxdelta);
            printf("%d %d\n", t[1].segments,
                   t[1].number);
        }

        if (color[i] == 'B') {
            update(1, 1, cord[i] - maxdelta, cord[i] + delta[i] - maxdelta);
            printf("%d %d\n", t[1].segments,
                   t[1].number);
        }
    }
    return 0;
}