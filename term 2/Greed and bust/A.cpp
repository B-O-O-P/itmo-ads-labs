#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, n;
vector<int> mincobblers;


int main() {
    freopen("cobbler.in", "r", stdin);
    freopen("cobbler.out", "w", stdout);

    scanf("%d %d", &K, &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mincobblers.push_back(x);
    }

    sort(mincobblers.begin(), mincobblers.end());

    int work = mincobblers[0];
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (work <= K) {
            count++;
            work += mincobblers[count];
        } else break;
    }

    printf("%d", count);

    return 0;
}