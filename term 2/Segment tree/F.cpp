#include <iostream>
#include <cmath>

int a[100001];
int st[100001][17];
int n, m;

void swap(int& a, int& b) {
    int tmp;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
}

void ST() {
    for (int i = 1; i <= n; i++)
        st[i][0] = i;

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if (a[st[i][j - 1]] < a[st[i + (1 << (j - 1))][j - 1]])
                st[i][j] = st[i][j - 1];
            else
                st[i][j] = st[i + (1 << (j - 1))][j - 1];
        }
    }
}

int getMin(int l, int r) {
    int k = (int) (log(1.0 * r - l + 1) / log(2.0));
    int res = st[l][k];

    if (a[st[r - (1 << k) + 1][k]] < a[res])
        res = st[r - (1 << k) + 1][k];

    return res;
}

int main() {
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    int ans = 0, u, v;
    scanf("%d %d %d %d %d", &n, &m, &a[1], &u, &v);

    for (int i = 2; i <= n; i++) {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
    }

    ST();
    for (int i = 1; i <= m; i++) {
        int uu = u;
        int vv = v;
        swap(uu, vv);
        ans = a[getMin(uu, vv)];
        if (i < m) {
            u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
            v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
        }
    }

    printf("%d %d %d", u, v, ans);

    return 0;
}