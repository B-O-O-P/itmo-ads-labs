#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long INF = (long long) 1e20;

int n, m, s;

struct Edge {
    int u, v;
    long long w;

    Edge(int u, int v, long long w) : u(u), v(v), w(w) {}
};

vector<Edge> edges;
vector<vector<int> > graph;
vector<int> used;
vector<long long> dist;

void findShortestWays() {
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;
            if ((dist[u] < INF) && (dist[v] > dist[u] + w)) {
                dist[v] = max(-INF, dist[u] + w);
            }
        }
    }
}

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (!used[to])
            dfs(to);
    }
}

int main() {
    cin >> n >> m >> s;
    s--;

    dist.assign(n, INF);
    graph.resize(n);
    used.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back(v);
        edges.push_back(Edge(u, v, w));
    }

    findShortestWays();
    used.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;
            if ((dist[u] < INF) && (dist[v] > dist[u] + w) && !used[v]) {
                dfs(v);
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) cout << "*\n";
        else if (used[i]) cout << "-\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}