#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> graph;
vector<int> used, enter, ret, colors, painted;
map<pair<int, int>, vector<int>> numbersOfEdges;
int time, n, m, maxColor;

pair<int, int> getEdge(int a, int b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    return make_pair(a, b);
};

void setColor(int v, int to, int color) {
    vector<int> numbers = numbersOfEdges[getEdge(v, to)];
    for (int i = 0; i < numbers.size(); ++i) {
        colors[numbers[i]] = color;
    }
};

void dfs(int v, int p = -1) {
    used[v] = 1;
    enter[v] = ret[v] = time++;
    int c = 0;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == p) continue;
        if (used[to]) {
            ret[v] = min(ret[v], enter[to]);
        } else {
            dfs(to, v);
            c++;
            ret[v] = min(ret[v], ret[to]);
        }
    }
}

void paint(int v, int color, int p) {
    painted[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == p) continue;
        if (!painted[to]) {
            if (ret[to] >= enter[v]) {
                int newColor = ++maxColor;
                setColor(v, to, newColor);
                paint(to, newColor, v);
            } else {
                setColor(v, to, color);
                paint(to, color, v);
            }
        } else if (enter[to] < enter[v]) {
            setColor(v, to, color);
        }
    }
}

void solve() {
    time = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    maxColor = 0;
    for (int i = 1; i <= n; ++i) {
        if (!painted[i]) {
            paint(i, maxColor, -1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    graph.resize(n + 1);
    used.resize(n + 1);
    painted.resize(n + 1);
    enter.resize(n + 1);
    ret.resize(n + 1);
    colors.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        int beg, end;
        scanf("%d %d", &beg, &end);

        graph[beg].push_back(end);
        graph[end].push_back(beg);

        numbersOfEdges[getEdge(beg, end)].push_back(i);
    }

    solve();

    printf("%d\n", maxColor);

    for (int i = 1; i <= m; ++i) {
        printf("%d ", colors[i]);
    }

    return 0;
}