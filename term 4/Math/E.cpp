#include <iostream>
#include <vector>

std::vector<long long> factorization(long long n) {
    std::vector<long long> res;
    for (long long i = 2; i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            res.push_back(n / i);
            break;
        }
    }
    return res;
}

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1 = 0, y1 = 0;
    long long d = gcd(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long Euclid(long long a, long long m) {
    long long x, y;
    long long res = gcd(a, m, x, y);
    return (x + m) % m;
}

long long mul(long long a, long long n, long long m) {
    long long res = 0;
    while (n > 0) {
        if (n % 2 == 1)
            res = (res + a) % m;
        a = (a + a) % m;
        n /= 2;
    }
    return res;
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

int main() {
    long long n, e, C;

    scanf("%lld %lld %lld", &n, &e, &C);

    std::vector<long long> f = factorization(n);
    long long p = (f[0] - 1) * (f[1] - 1);
    long long d = Euclid(e, p);

    printf("%lld", pow(C, d, n));

    return 0;
}