#include <iostream>
#include <vector>


using namespace std;

const int MAXN = 1001;
int graph[MAXN][MAXN], gg[MAXN][MAXN];
vector<bool> used;
int n;


void dfs(int v, bool direction) {
    used[v] = true;
    for (int i = 0; i < n; ++i) {
        if ((direction ? gg[i][v] : gg[v][i]) && !used[i]) dfs(i, direction);
    }
}

bool visitAll() {
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            return false;
    }

    return true;
}

int main() {
    freopen("avia.in", "r", stdin);
    freopen("avia.out", "w", stdout);

    scanf("%d", &n);
    used.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            graph[i][j] = x;
        }
    }

    int l = 0;
    int r = 1000000000;

    while (l < r) {
        int middle = (l + r) / 2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                gg[i][j] = (graph[i][j] <= middle);
            }
        }

        used.assign(n, false);
        dfs(0, false);
        bool done = false;
        if (visitAll()) {
            used.assign(n, false);
            dfs(0, true);
            if (!visitAll())
                done = true;
        } else {
            done = true;
        }

        if (!done) {
            r = middle;
        } else {
            l = middle + 1;
        }
    }

    printf("%d", l);
    return 0;
}