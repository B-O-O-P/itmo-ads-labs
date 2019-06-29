#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int time, n, m;
vector<vector<int>> graph;
vector<int> used, enter, ret;
set<int> bridges;
map<pair<int, int>, int> numberOfEdges;

pair<int, int> getEdge(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    return make_pair(a, b);
};

void dfs(int v, int p = -1) {
    used[v] = 1;
    enter[v] = ret[v] = time++;

    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (to == p) continue;
        if (used[to])
            ret[v] = min(ret[v], enter[to]);
        else {
            dfs(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] > enter[v]) bridges.insert(numberOfEdges[getEdge(v, to)]);

        }
    }
}


void findAll() {
    time = 1;

    for (int i = 0; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
};

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
        numberOfEdges[getEdge(beg, end)] = i;
    }

    findAll();

    printf("%d\n", bridges.size());

    int c = 0;

    for (auto iter = bridges.begin(); iter != bridges.end(); iter++) {
        if (c++) printf(" ");
        printf("%d", *iter);
    }

    return 0;
}