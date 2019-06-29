#include <iostream>
#include <vector>

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

long long kto(std::vector<long long>& a, std::vector<long long>& p) {
    long long result = 0;
    long long mul = 1;

    size_t n = a.size();

    std::vector<std::vector<long long>> r(n, std::vector<long long>(n));
    std::vector<long long> x(n);

    for (int i = 0; i < r.size(); ++i)
        for (int j = i + 1; j < p.size(); ++j) {
            r[i][j] = Euclid(p[i], p[j]);
        }

    for (int i = 0; i < n; ++i) {
        x[i] = a[i];

        for (int j = 0; j < i; ++j) {
            x[i] = (x[i] - x[j]) * r[j][i];
            x[i] = x[i] % p[i];

            if (x[i] < 0) {
                x[i] += p[i];
            }
        }

        result += mul * x[i];
        mul *= p[i];
    }
    return result;
}

int main() {
    std::vector<long long> a;
    std::vector<long long> p;

    for (int i = 0; i < 2; ++i) {
        long long aa;
        scanf("%lld", &aa);
        a.push_back(aa);
    }

    for (int i = 0; i < 2; ++i) {
        long long pp;
        scanf("%lld", &pp);
        p.push_back(pp);
    }

    printf("%lld\n", kto(a, p));
    return 0;
}