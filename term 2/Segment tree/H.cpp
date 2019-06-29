#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int minn(int a, int b) {
    if (a < b)
        return a;
    return b;
}

struct cord {
    int l;
    int r;
    int x;
    int id;

    cord() {};

};

bool compare(cord a, cord b) {
    return ((a.x > b.x) || ((a.x == b.x) && (a.id < b.id)));
}

int get(int* dsu, int v) {
    if (dsu[v] == v)
        return v;
    dsu[v] = get(dsu, dsu[v]);
    return dsu[v];
}

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    int* dsu = new int[n + 1];
    int l, r, x;
    int* ans = new int[n];
    int* lg = new int[n + 1];
    int** table = new int* [n];
    lg[1] = 0;

    if (n > 1)
        lg[2] = 1;

    for (int i = 3; i <= n; i++)
        if (i & (i - 1))
            lg[i] = lg[i - 1];
        else
            lg[i] = lg[i - 1] + 1;

    for (int i = 0; i < n; i++)
        ans[i] = INT_MAX;

    cord* a = new cord[q];

    for (int i = 0; i <= n; i++)
        dsu[i] = i;

    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &l, &r, &x);
        a[i].l = l - 1;
        a[i].r = r - 1;
        a[i].x = x;
        a[i].id = i;
    }

    sort(a, a + q, compare);
    for (int i = 0; i < q; i++) {
        l = a[i].l;
        r = a[i].r;
        x = a[i].x;
        for (int j = get(dsu, l); j <= r; j = get(dsu, j)) {
            dsu[j] = j + 1;
            ans[j] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        table[i] = new int[17];
        table[i][0] = ans[i];
    }

    for (int j = 1; j < 17; j++)
        for (int i = 0; i < n; i++)
            if (i + (1 << (j - 1)) < n)table[i][j] = minn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            else table[i][j] = minn(table[i][j - 1], INT_MAX + 1);

    for (int i = 0; i < q; i++) {
        l = a[i].l;
        r = a[i].r;
        x = a[i].x;
        if (minn(table[l][lg[r - l + 1]], table[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]) != x) {
            printf("inconsistent\n");
            return 0;
        }
    }

    printf("consistent\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    printf("\n");

    return 0;
}