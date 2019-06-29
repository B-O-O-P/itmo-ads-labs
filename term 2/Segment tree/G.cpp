#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, p;

struct Cord {
    int x;
    int up;
    int down;
    bool start;
};

struct Node {
    bool upd = false;
    int data = INT_MIN;
    int add = 0;
};

bool compare(Cord x1, Cord x2) {
    return (x1.x < x2.x) || (x1.x == x2.x && (x1.start || !x2.start));
}

vector<Node> t;

void push(int v) {
    if (!t[v].upd)
        return;

    if (v * 2 + 1 < n + p - 1) {
        if (t[v * 2 + 1].upd) {
            t[v * 2 + 1].add += t[v].add;
        } else {
            t[v * 2 + 1].upd = true;
            t[v * 2 + 1].add = t[v].add;
        }
    }

    if (v * 2 + 2 < n + p - 1) {
        if (t[v * 2 + 2].upd) {
            t[v * 2 + 2].add += t[v].add;
        } else {
            t[v * 2 + 2].upd = true;
            t[v * 2 + 2].add = t[v].add;
        }
    }

    t[v].upd = false;
    t[v].data += t[v].add;
}


void update(int v, int l, int r, int tl, int tr, int value) {
    if (l > tr || r < tl)
        return;

    if (tl >= l && r >= tr) {
        push(v);

        if (t[v].upd)
            t[v].add += value;
        else {
            t[v].upd = true;
            t[v].add = value;
        }

        push(v);
        int tm = (tl + tr) / 2;

        update(v * 2 + 1, l, r, tl, tm, value);
        update(v * 2 + 2, l, r, tm + 1, tr, value);

        int left, right;

        if (t[v * 2 + 1].upd) left = t[v * 2 + 1].data + t[v * 2 + 1].add;
        else left = t[v * 2 + 1].data;

        if (t[v * 2 + 2].upd) right = t[v * 2 + 2].data + t[v * 2 + 2].add;
        else right = t[v * 2 + 2].data;

        t[v].data = max(left, right);
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (v < n + p - 1) {
            t[v].data = 0;
            return;
        }
    }

    int tm = (tl + tr) / 2;

    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);

    t[v].data = max(t[v * 2 + 1].data, t[v * 2 + 2].data);
}

int cordY() {
    int max = t[0].data;
    int v = 0;
    while (v * 2 + 1 < n + p - 1) {
        push(v);
        int left;
        if (t[v * 2 + 1].upd)left = t[v * 2 + 1].data + t[v * 2 + 1].add;
        else left = t[v * 2 + 1].data;
        if (left == max)
            v = v * 2 + 1;
        else
            v = v * 2 + 2;
    }
    return v;
}

void upToDegree() {
    while (n > p) {
        p = p << 1;
    }
}

int main() {
    int nn, miny, maxy;
    p = 1;

    scanf("%d", &nn);

    vector<Cord> x((unsigned) 2 * nn);
    scanf("%d %d %d %d", &x[0].x, &x[0].up, &x[1].x, &x[0].down);

    x[0].start = true;
    x[1].start = false;
    x[1].up = x[0].up;
    x[1].down = x[0].down;

    miny = x[0].up;
    maxy = x[0].down;

    for (int i = 2; i < 2 * nn; i += 2) {
        scanf("%d %d %d %d", &x[i].x, &x[i].up, &x[i + 1].x, &x[i].down);

        x[i].start = true;
        x[i + 1].start = false;
        x[i + 1].up = x[i].up;
        x[i + 1].down = x[i].down;

        if (miny > x[i].up)
            miny = x[i].up;
        if (maxy < x[i].down)
            maxy = x[i].down;

    }

    sort(x.begin(), x.end(), compare);

    n = maxy + 1 - miny;
    upToDegree();

    int size = p << 1 - 1;
    t.resize((unsigned) size);

    build(0, 0, p - 1);

    int answer, cordx, cordy;
    int m = 0 - miny;
    int add;

    if (x[0].start)
        add = 1;
    else add = -1;

    update(0, x[0].up + m, x[0].down + m, 0, p - 1, add);
    answer = t[0].data;
    cordx = x[0].x;
    cordy = x[0].up;

    for (int i = 1; i < x.size(); i++) {
        if (x[i].start)
            add = 1;
        else add = -1;

        update(0, x[i].up + m, x[i].down + m, 0, p - 1, add);

        if (answer < t[0].data) {
            answer = t[0].data;
            cordx = x[i].x;
            cordy = cordY() - m - p + 1;
        }
    }

    printf("%d\n %d %d", answer, cordx, cordy);

    return 0;
}