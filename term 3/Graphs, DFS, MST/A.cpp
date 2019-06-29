#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
const int MAX_N = 100000;
std::vector<int> g[MAX_N];
bool used[MAX_N];
std::vector<int> answer;
char color[MAX_N];

void dfs(const int v) {
    used[v] = true;

    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!used[u]) {
            dfs(u);
        }
    }

    answer.push_back(v);
}

bool dfsForCycle(const int v) {
    color[v] = 'g';

    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (color[u] == 'w') {
            if (dfsForCycle(u)) return true;
        } else if (color[u] == 'g') {
            return true;
        }
    }

    color[v] = 'b';

    return false;
}

bool checkCycle() {
    for (int i = 0; i < n; ++i) {
        color[i] = 'w';
    }

    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        hasCycle = dfsForCycle(i);
        if (hasCycle) {
            answer.clear();
            std::cout << -1;
            break;
        }
    }

    return hasCycle;
}


void topSort() {
    if (!checkCycle()) {
        for (int i = 0; i < n; ++i) {
            used[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }

        std::reverse(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i) {
            std::cout << answer[i] + 1 << " ";
        }
    }
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int beg, end;
        std::cin >> beg >> end;
        beg--;
        end--;
        g[beg].push_back(end);
    }
    topSort();

    return 0;
}