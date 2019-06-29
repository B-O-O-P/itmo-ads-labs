#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
const int INF = 100000000;
const int NOEDGE = 100000;

struct Edge {
    int u, v, w;
};

vector<Edge> edges;

void findNegativeCycle() {
    vector<int> dist(n, INF);
    vector<int> p(n, -1);
    int x;
    dist[0] = 0;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < edges.size(); ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = max(-INF, dist[u] + w);
                p[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> cycle;
        int y = x;

        for (int i = 0; i < n; ++i) {
            y = p[y];
        }

        for (int cur = y;; cur = p[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() - 1 << endl;
        for (int i = 1; i < cycle.size(); ++i) {
            cout << cycle[i] + 1;
            if (i != cycle.size() - 1)
                cout << " ";
        }

        cout << endl;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            if (w != NOEDGE) {
                edges.push_back({i, j, w});
            }
        }
    }

    findNegativeCycle();

    return 0;
}