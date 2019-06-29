#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000 + 5;

int n;
std::vector<long long> prime;

void eratosthenesSieve() {
    prime.assign(INF + 1, true);

    for (long long i = 0; i < prime.size(); ++i) {
        prime[i] = i;
    }

    for (long long i = 2; i <= INF; ++i)
        if (prime[i] == i)
            for (long long j = i * i; j <= INF; j += i)
                prime[j] = i;

}

std::vector<long long> factorization(long long x) {
    std::vector<long long> res;

    while (x != 1) {
        res.push_back(prime[x]);
        x /= prime[x];
    }

    std::sort(res.begin(), res.end());

    return res;
}

int main() {
    scanf("%d", &n);
    eratosthenesSieve();

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        for (long long p : factorization(x)) {
            printf("%lld ", p);
        }

        printf("\n");
    }
    return 0;
}