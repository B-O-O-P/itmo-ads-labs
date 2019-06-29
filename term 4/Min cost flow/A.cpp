#include <iostream>
#include <climits>
#include <vector>
#include <deque>

size_t n, m;
const long long INF = LONG_LONG_MAX;

struct Edge {
    int from, to;
    long long flow, cap, cost;
    int reversed = -1;

    Edge(int from, int to, long long int f, long long int cap, long long int cost) : from(from), to(to), flow(f),
                                                                                     cap(cap),
                                                                                     cost(cost) {}

};

std::vector<std::vector<Edge>> edges;
std::vector<long long> d;
std::vector<int> id;
std::vector<Edge*> p;

void addEdge(int from, int to, long long flow, long long cap, long long cost) {
    Edge edge = Edge(from, to, flow, cap, cost);
    Edge rev = Edge(to, from, flow, 0, -cost);

    edges[from].push_back(edge);
    edges[to].push_back(rev);

    edges[from].back().reversed = edges[to].size() - 1;
    edges[to].back().reversed = edges[from].size() - 1;
}

long long levitAlgorithm() {
    long long minCost = 0;
    long long maxFlow = 0;
    while (true) {
        std::deque<int> q;
        id.assign(n + 1, 0);
        d.assign(n + 1, INF);
        p.resize(n + 1);

        d[1] = 0;
        q.push_back(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            id[u] = 2;

            for (Edge& edge : edges[u]) {
                if (edge.flow < edge.cap && d[edge.to] > d[edge.from] + edge.cost) {
                    d[edge.to] = d[edge.from] + edge.cost;

                    if (!id[edge.to]) {
                        q.push_back(edge.to);
                    } else if (id[edge.to] == 2) {
                        q.push_front(edge.to);
                    }

                    id[edge.to] = 1;
                    p[edge.to] = &edge;
                }
            }
        }

        long long del = INF;

        if (d[n] == INF) {
            break;
        } else {
            for (int u = n; u != 1; u = p[u]->from) {
                Edge* edge = p[u];

                del = std::min(del, edge->cap - edge->flow);
            }

            for (int u = n; u != 1; u = p[u]->from) {
                Edge* edge = p[u];
                Edge* reversed = &edges[edge->to][edge->reversed];

                edge->flow += del;
                reversed->flow -= del;

                minCost += del * edge->cost;
            }

            maxFlow += del;
        }
    }

    return minCost;
}

int main() {
    freopen("mincost.in", "r", stdin);
    freopen("mincost.out", "w", stdout);
    std::cin >> n >> m;
    edges.assign(n + 1, std::vector<Edge>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        long long cap, cost;
        std::cin >> from >> to >> cap >> cost;

        addEdge(from, to, 0, cap, cost);
    }
    std::cout << levitAlgorithm();
    return 0;
}