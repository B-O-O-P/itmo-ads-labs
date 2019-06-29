#include <iostream>
#include <vector>

const int INF = 2 * 10000000 + 5;

int n;
std::vector<char> prime;

void eratosthenesSieve() {
    prime.assign(INF + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= INF; ++i)
        if (prime[i])
            if (i * 1ll * i <= INF)
                for (int j = i * i; j <= INF; j += i)
                    prime[j] = false;

}

bool isPrime(int n) {
    return prime[n];
}

int main() {
    scanf("%d", &n);
    eratosthenesSieve();

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        isPrime(x) ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}