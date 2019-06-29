#include <iostream>

using namespace std;

int getMiddle(int l, int r) {
    return l + (r - l) / 2;
}

void updating(long long* st, int tl, int tr, int i, long long diff, int ind) {
    if (i < tl || i > tr) {
        return;
    }

    st[ind] = st[ind] + diff;
    if (tr != tl) {
        int mid = getMiddle(tl, tr);
        updating(st, tl, mid, i, diff, 2 * ind + 1);
        updating(st, mid + 1, tr, i, diff, 2 * ind + 2);
    }
}

void update(long long* a, long long* st, int n, int i, long long new_Value) {
    long long diff = new_Value - a[i];
    a[i] = new_Value;
    updating(st, 0, n - 1, i, diff, 0);
}

long long buildTree(long long* a, int tl, int tr, long long* st, int ind) {
    if (tl == tr) {
        st[ind] = a[tl];
        return a[tl];
    }

    int mid = getMiddle(tl, tr);
    st[ind] = buildTree(a, tl, mid, st, ind * 2 + 1) + buildTree(a, mid + 1, tr, st, ind * 2 + 2);

    return st[ind];
}

long long sum(long long* st, int tl, int tr, int l, int r, int ind) {
    if (l <= tl && r >= tr) {
        return st[ind];
    }

    if (tr < l || tl > r) {
        return 0;
    }

    int mid = getMiddle(tl, tr);

    return sum(st, tl, mid, l, r, 2 * ind + 1) + sum(st, mid + 1, tr, l, r, 2 * ind + 2);

}

long long* buildingTree(long long* a, int n) {
    long long* st = new long long[4 * n];
    buildTree(a, 0, n - 1, st, 0);
    return st;
}

long long get(long long* st, int n, int l, int r) {
    return sum(st, 0, n - 1, l, r, 0);
}


int main() {
    freopen("rsq.in", "r", stdin);
    freopen("rsq.out", "w", stdout);

    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long* st = buildingTree(a, n);
    string s;

    while (cin >> s) {
        if (s == "sum") {
            int i, j;
            cin >> i;
            cin >> j;
            cout << get(st, n, i - 1, j - 1) << "\n";
        }
        if (s == "set") {
            int i;
            long long x;
            cin >> i;
            cin >> x;
            update(a, st, n, i - 1, x);
        }
    }

    return 0;
}