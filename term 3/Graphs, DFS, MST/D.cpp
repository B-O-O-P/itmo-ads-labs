#include <iostream>

#include <vector>
#include <set>
#include <map>

using namespace std;

int time, n, m, maxColor;
vector<vector<int>> graph;
vector<int> used, enter, ret, colors, mult;
set<int> bridges;
map<pair<int, int>, int> numberOfEdge;

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
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];

        if (to == p) continue;

        if (used[to])
            ret[v] = min(ret[v], enter[to]);
        else {
            dfs(to, v);
            ret[v] = min(ret[v], ret[to]);
            if (ret[to] > enter[v] && !mult[numberOfEdge[getEdge(v, to)]])
                bridges.insert(numberOfEdge[getEdge(v, to)]);
        }
    }
}

void paint(int v, int color) {
    colors[v] = color;

    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];

        if (colors[to] == 0) {
            if (bridges.find(numberOfEdge[getEdge(v, to)]) != bridges.end()) {
                maxColor++;
                paint(to, maxColor);
            } else {
                paint(to, color);
            }
        }
    }
}

void solve() {
    time = 1;

    for (int i = 1; i <= n; ++i) {
        colors[i] = 0;
        if (!used[i])
            dfs(i);
    }

    maxColor = 0;
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == 0) {
            maxColor++;
            paint(i, maxColor);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    graph.resize(n + 1);
    used.resize(n + 1);
    enter.resize(n + 1);
    ret.resize(n + 1);
    colors.resize(n + 1);
    mult.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        int beg, end;
        scanf("%d %d", &beg, &end);

        graph[beg].push_back(end);
        graph[end].push_back(beg);
        if (numberOfEdge[getEdge(beg, end)] == 0) {
            numberOfEdge[getEdge(beg, end)] = i;
        } else {
            mult[numberOfEdge[getEdge(beg, end)]] = true;
        }
    }

    solve();

    printf("%d\n", maxColor);

    for (int i = 1; i <= n; ++i) {
        printf("%d ", colors[i]);
    }

    return 0;
}