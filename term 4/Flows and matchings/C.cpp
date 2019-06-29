#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 0x3F3F3F3F;
size_t n, m;
int s, t;
std::vector<std::vector<int>> graph;
std::vector<int> d, p, path;
std::queue<int> q;
std::vector<bool> used;

struct Edge {
    int a, b, c, f;
};
std::vector<Edge> edges;

int dfs(int u, int flow) {
    if (u == t || flow == 0) {
        return flow;
    }
    for (; p[u] < graph[u].size(); ++p[u]) {
        int id = graph[u][p[u]];
        int v = edges[id].b;
        if (d[v] == d[u] + 1) {
            int pushed = dfs(v, std::min(flow, edges[id].c - edges[id].f));
            if (pushed) {
                edges[id].f += pushed;
                edges[id ^ 1].f -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

bool bfs() {
    d.assign(n, INF);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int id = graph[u][i];//number of edge (uv)
            int v = edges[id].b;

            if (d[v] == INF && edges[id].f < edges[id].c) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t] != INF;
}

int algoDinic() {
    int flow = 0;
    while (bfs()) {
        p.assign(n, 0);
        int f = dfs(s, INF);
        while (f) {
            flow += f;
            f = dfs(s, INF);
        }
    }
    return flow;
}

void dfs2(int u) {
    path.push_back(u);

    if (u == t) {
        return;
    }

    for (int id : graph[u]) {
        int v = edges[id].b;

        if (!used[id] && edges[id].f == 1) {
            used[id] = true;
            dfs2(v);
            break;
        }
    }
}

void printPath() {
    dfs2(s);

    for (int i : path) {
        std::cout << i + 1 << " ";
    }
    std::cout << "\n";

    path.clear();
}

int main() {
    std::cin >> n >> m;
    graph.resize(n);
    d.resize(n);
    p.resize(n);
    std::cin >> s >> t;
    s--;
    t--;

    for (int i = 0; i < m; ++i) {
        int ai, bi;
        std::cin >> ai >> bi;
        ai--;
        bi--;


        graph[ai].push_back(edges.size());
        edges.push_back({ai, bi, 1, 0});
        graph[bi].push_back(edges.size());
        edges.push_back({bi, ai, 0, 0});
    }

    int maxFlow = algoDinic();

    if (maxFlow < 2) {
        std::cout << "NO";
    } else {
        std::cout << "YES\n";

        used.assign(2 * m, false);

        printPath();

        printPath();
    }
    return 0;
}