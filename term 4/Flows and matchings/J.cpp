#include <iostream>
#include <vector>

const long long INF = 10000000000;

size_t n, w;
std::vector<long long> d;
std::vector<bool> used;
std::vector<std::vector<long long>> graph;

struct Object {
    long long x1, y1, x2, y2;

    long long getMinY() {
        return std::min(y1, y2);
    }

    long long getMaxY() {
        return std::max(y1, y2);
    }
};

std::vector<Object> objects;

long long getDistance(Object first, Object second) {
    long long h = (first.x1 <= second.x1) ? (second.x1 - first.x2) : (first.x1 - second.x2);
    long long v = (first.y1 <= second.y1) ? (second.y1 - first.y2) : (first.y1 - second.y2);
    return std::max(h, v) < 0 ? 0 : std::max(h, v);
}

void dijkstra() {
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        long long v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }

        used[v] = true;
        for (int u = 0; u < n; ++u) {
            if (v != u) {
                long long distance = graph[v][u];
                if (d[v] + distance < d[u]) {
                    d[u] = d[v] + distance;
                }
            }
        }

    }
}

int main() {
    d.assign(10000, INF);
    used.assign(10000, false);

    std::cin >> n >> w;
    graph.assign(n + 2, std::vector<long long>(n + 2));

    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        objects.push_back({x1, y1, x2, y2});
    }
    graph[0][n + 1] = w;
    graph[n + 1][0] = w;

    for (int i = 0; i < n; ++i) {
        Object current = objects[i];

        long long minY = current.getMinY();
        long long maxY = current.getMaxY();

        graph[0][i + 1] = w - maxY;
        graph[i + 1][0] = w - maxY;

        graph[n + 1][i + 1] = minY;
        graph[i + 1][n + 1] = minY;

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                graph[i + 1][j + 1] = getDistance(current, objects[j]);
                graph[j + 1][i + 1] = getDistance(current, objects[j]);
            }
        }
    }

    n += 2;
    dijkstra();

    std::cout << ((d[n - 1] == INF) ? 0 : d[n - 1]) << "\n";
    return 0;
}