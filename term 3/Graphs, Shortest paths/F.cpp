#include <iostream>
#include <vector>
#include <set>


using namespace std;


int n, m, a, b, c;
const long long INF = (long long) 1e18;

vector<long long> dijkstra(vector<vector<pair<int, long long>>>& graph, int start) {
    vector<long long> distances(n, INF);
    distances[start] = 0;
    set<pair<long long, int>> queue;
    queue.insert({0, start});
    while (!queue.empty()) {
        auto top = queue.begin();
        int u = top->second;
        queue.erase(top);
        for (auto next: graph[u]) {
            int v = next.first;
            long long length = next.second;
            if (distances[v] > distances[u] + length) {
                if (queue.find({distances[v], v}) != queue.end())
                    queue.erase(queue.find({distances[v], v}));
                distances[v] = distances[u] + length;
                queue.insert({distances[v], v});
            }
        }
    }

    return distances;
}

int main() {
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph;
    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cin >> a >> b >> c;
    a--;
    b--;
    c--;

    vector<long long> distancesFromA = dijkstra(graph, a);
    vector<long long> distancesFromB = dijkstra(graph, b);
    vector<long long> distancesFromC = dijkstra(graph, c);

    long long res = INF;
    for (int i = 0; i < n; i++) {
        long long distanceFromAtoX = distancesFromA[i];
        long long distanceFromBtoX = distancesFromB[i];
        long long distanceFromCtoX = distancesFromC[i];

        if (distancesFromA[i] != INF || distancesFromB[i] != INF || distancesFromC[i] != INF) {
            long long minDistance = min(distanceFromAtoX, distanceFromBtoX);
            minDistance = min(minDistance, distanceFromCtoX);
            if (minDistance == distanceFromAtoX) {
                res = min(res, 2 * minDistance + distanceFromBtoX + distanceFromCtoX);
            }
            if (minDistance == distanceFromBtoX) {
                res = min(res, 2 * minDistance + distanceFromAtoX + distanceFromCtoX);
            }
            if (minDistance == distanceFromCtoX) {
                res = min(res, 2 * minDistance + distanceFromBtoX + distanceFromAtoX);
            }
        } else continue;
    }

    if (res != INF)
        cout << res;
    else cout << "-1";

    return 0;
}