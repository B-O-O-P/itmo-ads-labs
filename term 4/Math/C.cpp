#include <iostream>
#include <cmath>

long long n;

long long mul(long long a, long long n, long long m) {
    long long r = 0;
    while (n > 0) {
        if (n % 2 == 1)
            r = (r + a) % m;
        a = (a + a) % m;
        n /= 2;
    }
    return r;
}

long long pow(long long a, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if ((n & 1) > 0)
            res = mul(res, a, m);
        a = mul(a, a, m);
        n >>= 1;
    }
    return res;
}

bool isPrime(long long val, long long k) {
    if (val == 2 || n == 3) {
        return true;
    }

    if (val == 1 || val % 2 == 0) {
        return false;
    }

    long long p = 0, q = val - 1;

    while (q % 2 == 0) {
        ++p;
        q /= 2;
    }

    for (int i = 0; i < k; i++) {
        long long a = (rand() % (val - 2)) + 2;
        long long x = pow(a, q, val);

        if (x == 1 || x == val - 1)
            continue;

        for (int j = 1; j < p; ++j) {
            x = mul(x, x, val);
            if (x == 1)
                return false;
            if (x == val - 1)
                break;
        }

        if (x != val - 1)
            return false;
    }

    return true;
}


int main() {
    scanf("%lld", &n);
    int k = 10;

    for (int i = 0; i < n; ++i) {
        long long x;
        scanf("%lld", &x);

        isPrime(x, k) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}