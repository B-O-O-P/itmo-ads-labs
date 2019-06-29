#include <iostream>
#include <vector>

const int INF = 1000000001;

size_t n;
std::vector<std::vector<int>> C;

std::pair<int, std::vector<int>> hunragianAlgo(std::vector<std::vector<int>> C, size_t n, size_t m) {
    std::vector<int> u(n + 1);
    std::vector<int> v(m + 1);
    std::vector<int> match(m + 1);
    std::vector<int> way(m + 1);

    for (int i = 1; i <= m; ++i) {
        match[0] = i;
        int currentColumn = 0;
        std::vector<int> minV(m + 1, INF);
        std::vector<char> used(m + 1, false);

        do {
            used[currentColumn] = true;
            int currentRow = match[currentColumn];
            int del = INF;
            int minColumn = 0;

            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int current = C[currentRow][j] - u[currentRow] - v[j];//potential

                    if (current < minV[j]) {
                        minV[j] = current;
                        way[j] = currentColumn;
                    }

                    if (minV[j] < del) {
                        del = minV[j];
                        minColumn = j;
                    }
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[match[j]] += del;
                    v[j] -= del;
                } else {
                    minV[j] -= del;
                }
            }

            currentColumn = minColumn;
        } while (match[currentColumn] != 0);

        do {
            int minColumn = way[currentColumn];
            match[currentColumn] = match[minColumn];
            currentColumn = minColumn;
        } while (currentColumn);
    }

    std::vector<int> result(n + 1);
    for (int j = 1; j <= m; ++j) {
        result[match[j]] = j;
    }

    return {-v[0], result};
}

int main() {
    freopen("assignment.in", "r", stdin);
    freopen("assignment.out", "w", stdout);

    std::cin >> n;
    C.assign(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> C[i][j];
        }
    }

    std::pair<int,std::vector<int>> result = hunragianAlgo(C,n,n);

    std::cout<< result.first << "\n";
    for (int i =1;i<=n;++i){
        std::cout<< i << " " << result.second[i] << "\n";
    }

    return 0;
}