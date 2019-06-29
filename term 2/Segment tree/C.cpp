#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMiddle(int l, int r) {
    return l + (r - l) / 2;
}

struct Node {
    long long data;
    long long add;
    long long set;
    long long l;
    long long r;
    bool up;

    Node() {
        data = LONG_LONG_MAX;
        add = 0;
        set = LONG_LONG_MAX;
        up = false;
    }

    Node(long long d, long long a, long long s, long left, long right, bool u) {
        data = d;
        add = a;
        set = s;
        l = left;
        r = right;
        up = u;
    }
};


vector <Node> t;
vector<long long> a;
int n;


void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = Node(a[tl], 0, a[tl], tl, tr, false);
    } else {
        int tm = getMiddle(tl, tr);
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = Node(min(t[2 * v].data, t[2 * v + 1].data), 0, 0, tl, tr, false);
        t[v].set = t[v].data;
    }
}

void pushset(int v) {
    if (!t[v].up)
        return;

    t[v].data = t[v].set;
    t[v].up = false;

    if (t[v].l == t[v].r)
        return;

    t[v * 2].set = t[v].set;
    t[v * 2 + 1].set = t[v].set;

    t[v * 2].up = true;
    t[v * 2 + 1].up = true;

    t[v * 2].add = 0;
    t[v * 2 + 1].add = 0;
}

void push(int v) {
    pushset(v);
    if (t[v].add == 0)
        return;

    t[v].data += t[v].add;
    t[v].set = t[v].data;

    long long addi = t[v].add;
    t[v].add = 0;

    if (t[v].l == t[v].r)
        return;

    t[2 * v].add += addi;
    t[2 * v + 1].add += addi;
}

void updateset(int v, long long value, int l, int r) {
    if (t[v].r < l || t[v].l > r)
        return;

    if (t[v].r <= r && t[v].l >= l) {
        t[v].add = 0;
        pushset(v);

        t[v].set = value;
        t[v].up = true;

        return;
    }
    push(v);

    updateset(2 * v, value, l, r);
    updateset(2 * v + 1, value, l, r);

    t[v].data = min(t[v * 2].set + t[v * 2].add, t[v * 2 + 1].set + t[v * 2 + 1].add);
    t[v].set = t[v].data;
}

void updateadd(int v, long long value, int l, int r) {
    if (t[v].r < l || t[v].l > r)
        return;

    if (t[v].r <= r && t[v].l >= l) {
        push(v);
        t[v].add = value;
        return;
    }

    push(v);

    updateadd(2 * v, value, l, r);
    updateadd(2 * v + 1, value, l, r);

    t[v].data = min(t[v * 2 + 1].set + t[v * 2 + 1].add, t[v * 2].set + t[v * 2].add);
    t[v].set = t[v].data;
}

long long get(int v, int l, int r) {
    if (t[v].r < l || t[v].l > r)
        return LONG_LONG_MAX;

    if (t[v].r <= r && t[v].l >= l) {
        push(v);
        return t[v].data;
    }

    push(v);

    return min(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

int main() {
    freopen("rmq2.in", "r", stdin);
    freopen("rmq2.out", "w", stdout);

    scanf("%d ", &n);
    a.resize((unsigned) n);
    t.resize((unsigned) 4 * n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    build(1, 0, n - 1);
    char* s = new char[n + 2];
    while (scanf("%s", s) != EOF) {
        int l, r;
        long long x;

        if (s[0] == 'm') {
            scanf("%d %d", &l, &r);
            printf("%lld\n", get(1, l - 1, r - 1));
        }

        if (s[0] == 's') {
            scanf("%d %d %lld", &l, &r, &x);
            updateset(1, x, l - 1, r - 1);
        }

        if (s[0] == 'a') {
            scanf("%d %d %lld", &l, &r, &x);
            updateadd(1, x, l - 1, r - 1);
        }
    }

    return 0;
}