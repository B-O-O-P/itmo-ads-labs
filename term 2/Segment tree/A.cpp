#include <iostream>

using namespace std;

int main() {
    freopen("sum0.in", "r", stdin);
    freopen("sum0.out", "w", stdout);

    int n, x, y, m, z, t;
    cin >> n >> x >> y;

    int* a = new int[n];
    long long* pref = new long long[n];

    cin >> a[0];
    pref[0] = a[0];
    cin >> m >> z >> t;
    int* b = new int[2 * m];
    int* c = new int[2 * m];
    cin >> b[0];

    for (int i = 1; i < n; i++) {
        a[i] = (x * a[i - 1] + y) % (1 << 16);
        pref[i] = a[i] + pref[i - 1];
    }

    for (int i = 1; i < 2 * m; i++) {
        b[i] = (z * b[i - 1] + t) % (1 << 30);
        if (b[i] < 0) b[i] = (1 << 30) + b[i];
    }

    for (int i = 0; i < 2 * m; i++) {
        c[i] = b[i] % n;
    }

    long long res = 0;
    for (int i = 0; i < m; i++) {
        int r = max(c[2 * i], c[2 * i + 1]);
        int l = min(c[2 * i], c[2 * i + 1]);
        if (l > 0) res += pref[r] - pref[l - 1];
        else res += pref[r];
    }

    cout << res;

    return 0;
}