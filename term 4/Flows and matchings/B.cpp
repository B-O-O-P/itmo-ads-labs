#include <iostream>
#include <vector>
#include <queue>

const int INF = 0x3F3F3F3F;
size_t n, m;
int s, t;
std::vector<std::vector<int>> graph;
std::vector<int> d, p;
std::queue<int> q;
std::vector<bool> reached;
struct Edge {
    int a, b, c, f;
};
std::vector<Edge> edges;

void dfs(int v) {
    reached[v] = true;

    for (int &edge : graph[v]) {
        if (edges[edge].f < edges[edge].c && !reached[edges[edge].b]) {
            dfs(edges[edge].b);
        }
    }
}

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

long long algoDinic() {
    long long flow = 0;
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

int main() {
    std::cin >> n >> m;
    graph.resize(n);
    d.resize(n);
    p.resize(n);
    reached.assign(n, false);
    s = 0;
    t = n - 1;

    for (int i = 0; i < m; ++i) {
        int ai, bi, ci;
        std::cin >> ai >> bi >> ci;
        ai--;
        bi--;

        graph[ai].push_back(edges.size());
        edges.push_back({ai, bi, ci, 0});
        graph[bi].push_back(edges.size());
        edges.push_back({bi, ai, ci, 0});
    }

    long long minCutFlow = algoDinic();
    std::vector<int> cut;

    dfs(s);
    for (int i = 0; i < 2 * m; i += 2) {
        if ((reached[edges[i].a] && !reached[edges[i].b]) || (!reached[edges[i].a] && reached[edges[i].b])) {
            cut.push_back(i / 2);
        }
    }

    std::cout << cut.size() << " " << minCutFlow << "\n";

    for (int i : cut) {
        std::cout << i + 1 << " ";
    }

    return 0;
}