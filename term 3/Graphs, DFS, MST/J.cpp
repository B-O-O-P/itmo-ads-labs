#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int n, m;
vector<int> parent, size;


class Edge {
public:
    int u, v;
    long long w;
};

vector<Edge> graph;

int compare(Edge a, Edge b) {
    return (a.w < b.w);
}

int getDSU(int v) {
    if (v != parent[v])
        parent[v] = getDSU(parent[v]);
    return parent[v];
}

void uniteDsu(int x, int y) {
    x = getDSU(x);
    y = getDSU(y);

    if (size[x] < size[y]) {
        x = x + y;
        y = x - y;
        x = x - y;
    }

    parent[y] = x;
    size[x] += size[y];

}

int main() {
    cin >> n >> m;
    graph.resize(m);
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[i].u = u - 1;
        graph[i].v = v - 1;
        graph[i].w = w;
    }

    sort(graph.begin(), graph.begin() + m, compare);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = i;
    }

    long long res = 0;
    for (int i = 0; i < m; ++i) {
        int v = graph[i].v;
        int u = graph[i].u;
        long long w = graph[i].w;
        if (getDSU(v) != getDSU(u)) {
            res += w;
            uniteDsu(v, u);
        }
    }

    cout << res;

    return 0;
}