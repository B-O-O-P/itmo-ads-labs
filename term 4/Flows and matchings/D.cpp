#include <iostream>
#include <vector>

size_t n, m;
std::vector<std::vector<int>> graph;
std::vector<int> matching;
std::vector<char> used;

bool kuhn(int u) {
    if (used[u]) {
        return false;
    }
    used[u] = true;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (matching[v] == -1 || kuhn(matching[v])) {
            matching[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    std::cin >> n >> m;
    graph.resize(n);
    matching.assign(m, -1);

    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        while (v != 0) {
            graph[i].push_back(v - 1);
            std::cin >> v;
        }
    }

    for (int i = 0; i < n; ++i) {
        used.assign(n, false);
        kuhn(i);
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        if (matching[i] != -1) {
            count++;
        }
    }

    std::cout << count << "\n";

    for (int i = 0; i < m; ++i) {
        if (matching[i] != -1) {
            std::cout << matching[i] + 1 << " " << i + 1 << "\n";
        }
    }
    return 0;
}