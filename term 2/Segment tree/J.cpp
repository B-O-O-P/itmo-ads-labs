#include <iostream>
#include <climits>

using namespace std;

long long MAX = 1000000000;

struct Node {
    long long min;
    long long set;
    long long l;
    long long r;
    bool up;
};

long long n, m, x;
Node* t;


long long min(long long l, long long r) {
    if (l < r)return l;
    else return r;
}


void push(long long current) {
    long long value = t[current].set;
    t[current].up = false;

    long long left = (current * 2) + 1;
    long long right = (current * 2) + 2;

    if (t[left].min < value) {
        t[left].set = value;
        t[left].up = true;
        t[left].min = value;
    }

    if (t[right].min < value) {
        t[right].set = value;
        t[right].up = true;
        t[right].min = value;
    }

}

long long get(long long l, long long r, long long v) {
    if (l > t[v].r || r < t[v].l)
        return MAX;

    if (l <= t[v].l && r >= t[v].r) {
        return t[v].min;
    }

    if (t[v].up) push(v);

    long long res = min(get(l, r, v * 2 + 1), get(l, r, v * 2 + 2));
    t[v].min = min(t[v * 2 + 1].min, t[v * 2 + 2].min);

    return res;
}


void set(long long l, long long r, long long value, long long v) {
    if (l > t[v].r || r < t[v].l)
        return;

    if (l <= t[v].l && r >= t[v].r) {
        if (value > t[v].min) {
            t[v].up = true;
            t[v].set = value;
            t[v].min = value;
        }
        return;
    }

    if (t[v].up) push(v);

    set(l, r, value, 2 * v + 1);
    set(l, r, value, 2 * v + 2);

    t[v].min = min(t[v * 2 + 1].min, t[v * 2 + 2].min);
}

long long ind(long long l, long long r, long long v, long long value) {
    if (l > t[v].r || r < t[v].l)
        return -1;

    if (t[v].l == t[v].r) {
        if (t[v].min == value)
            return v;
        else return -1;
    }

    if (t[v].up) push(v);

    if (t[v * 2 + 1].min <= value) {
        long long i = ind(l, r, v * 2 + 1, value);
        if (i > 0) return i;
    }

    return ind(l, r, v * 2 + 2, value);
}

void upToDegree() {
    x = 1;
    while (n > x) {
        x = x << 1;
    }
}

void build() {
    for (long long i = x - 1; i > 0;) {
        i--;
        t[i].min = min(t[2 * i + 1].min, t[2 * i + 2].min);
        t[i].l = t[2 * i + 1].l;
        t[i].r = t[2 * i + 2].r;
    }
}

int main() {
    cin >> n;
    cin >> m;
    MAX = MAX * MAX + 1;
    upToDegree();

    long long size = x << 1;
    t = new Node[size];

    for (long long i = 0; i < size; i++) {
        t[i].min = MAX;
        t[i].set = 0;
        t[i].l = i;
        t[i].r = i;
        t[i].up = false;
    }

    for (long long i = 0; i < n; i++) {
        t[x + i - 1].min = 0;
    }

    build();
    string s;

    for (long long i = 0; i < m; i++) {
        long long l, r, val;
        cin >> s;
        cin >> l;
        cin >> r;

        if (s == "attack") {
            long long res = get(x + l - 2, x + r - 2, 0);
            cout << res << " " << ind(x + l - 2, x + r - 2, 0, res) + 2 - x << "\n";
        } else {
            cin >> val;
            set(x + l - 2, x + r - 2, val, 0);
        }
    }

    return 0;
}