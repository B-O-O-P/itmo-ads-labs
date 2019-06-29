#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<int> used, enter, ret;
set<int> artPoints;
int time, n, m;

//p - parent
void dfs(int v, int p = -1) {
    used[v] = 1;
    enter[v] = ret[v] = time++;
    int c = 0;//child
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == p) continue;
        if (used[to]) {
            ret[v] = min(ret[v], enter[to]);
        } else {
            dfs(to, v);
            c++;
            ret[v] = min(ret[v], ret[to]);
            if ((ret[to] >= enter[v]) && (p != -1)) artPoints.insert(v);
        }
    }
    if ((p == -1) && (c > 1)) artPoints.insert(v);
}

void findAll() {
    time = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    graph.resize(n + 1);
    used.resize(n + 1);
    enter.resize(n + 1);
    ret.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int beg, end;
        scanf("%d %d", &beg, &end);

        graph[beg].push_back(end);
        graph[end].push_back(beg);
    }

    findAll();

    printf("%d\n", artPoints.size());

    for (auto iter = artPoints.begin(); iter != artPoints.end(); ++iter) {
        printf("%d ", *iter);
    }

    return 0;
}