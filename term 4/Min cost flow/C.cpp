#include <iostream>
#include <vector>

const int INF = 1000000001;

size_t N, K, P;
std::vector<char> usedV;
std::vector<std::vector<int>> C, A;
std::vector<std::vector<int>> edges;
std::vector<std::vector<int>> children;
std::vector<std::vector<std::vector<int>>> d;


std::pair<int, std::vector<int>> hungarianAlgo(std::vector<std::vector<int>>& C, size_t n, size_t m) {
    std::vector<int> u(n + 1);
    std::vector<int> v(m + 1);
    std::vector<int> match(m + 1);
    std::vector<int> way(m + 1);

    for (int i = 1; i <= n; ++i) {
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

int dfs(int v) {
    int minCost = INF;

    for (int to: children[v]) {
        dfs(to);
    }

    for (int parentColor = 1; parentColor <= K; ++parentColor)
        for (int color = 1; color <= K; ++color) {
            if (!children[v].empty()) {
                d[v][color][parentColor] = P + C[v][color];
            }

            for (int child: children[v]) {
                int cost = INF;

                for (int child_color = 1; child_color <= K; ++child_color) {
                    cost = std::min(cost, d[child][child_color][color]);
                }

                d[v][color][parentColor] += cost;
            }

            if ((!children[v].empty() && children[v].size() <= K - 1) || (v == 1 && children[v].size() <= K)) {
                for (int i = 0; i < children[v].size(); ++i) {
                    for (int childColor = 1; childColor <= K; ++childColor) {
                        if (childColor != parentColor || v == 1) {
                            A[i + 1][childColor] = d[children[v][i]][childColor][color];
                        } else {
                            A[i + 1][childColor] = INF;
                        }
                    }
                }

                d[v][color][parentColor] = std::min(d[v][color][parentColor],
                                                    hungarianAlgo(A, children[v].size(), K).first +
                                                    C[v][color]);

            }

            minCost = std::min(minCost, d[v][color][parentColor]);
        }

    return minCost;
}

void buildTree(int v) {
    usedV[v] = true;

    for (int to : edges[v]) {
        if (!usedV[to]) {
            children[v].push_back(to);
            buildTree(to);
        }
    }

    if (children[v].empty()) {
        for (int color = 1; color <= K; ++color) {
            for (int parent = 0; parent <= K; ++parent) {
                d[v][color][parent] = C[v][color];
            }
        }
    }
}

int main() {
    std::cin >> N >> K >> P;

    usedV.assign(N + 1, false);
    C.assign(N + 1, std::vector<int>(K + 1));
    A.assign(N + 3, std::vector<int>(K + 3));
    edges.assign(N + 1, std::vector<int>());
    children.assign(N + 1, std::vector<int>());
    d.assign(N + 1, std::vector<std::vector<int>>(K + 1, std::vector<int>(K + 1)));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            std::cin >> C[i][j];
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        int from, to;
        std::cin >> from >> to;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    buildTree(1);
    dfs(1);

    int result = INF;

    for (int color = 1; color <= K; ++color) {
        result = std::min(result, d[1][color][1]);
    }

    std::cout << result << "\n";

    return 0;
}