#include <iostream>
#include <vector>

using namespace std;

int n, m, s, k;
const long long INF = (long long) 1e19;
vector<vector<long long>> dist;

struct Edge {
    Edge(int i, int i1, long long int i2) : u(i), v(i1), w(i2) {}

    int u, v;
    long long w;
};

vector<Edge> edges;

void findKPaths() {
    dist = vector<vector<long long>>(k + 1, vector<long long>(n, INF));
    dist[0][s] = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            long long w = edges[j].w;
            if (dist[i][u] < INF)
                dist[i + 1][v] = min(dist[i + 1][v], dist[i][u] + w);
        }
    }
}

int main() {
    cin >> n >> m >> k >> s;
    s--;

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({u, v, w});
    }

    findKPaths();
    for (int i = 0; i < n; ++i) {
        if (dist[k][i] == INF) {
            cout << "-1\n";
        } else cout << dist[k][i] << "\n";
    }

    return 0;
}