#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int n;
vector<pair<int, int>> points;
vector<bool> used;
vector<int> selectedEdge;
vector<double> minEdge;

const int INF = 1000000000;


double distance(int v, int to) {
    if (v == to)
        return INF;
    pair<int, int> a = points[v];
    pair<int, int> b = points[to];
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}


int main() {
    scanf("%d", &n);
    used.resize(n);
    minEdge.resize(n);
    selectedEdge.resize(n);


    minEdge.assign(n, INF);
    selectedEdge.assign(n, -1);
    minEdge[0] = 0;

    for (int i = 0; i < n; ++i) {
        int xi, yi;
        scanf("%d %d", &xi, &yi);
        points.emplace_back(make_pair(xi, yi));
    }

    double res = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v])) {
                v = j;
            }
        }

        used[v] = true;
        if (selectedEdge[v] != -1) {
            res += (distance(v, selectedEdge[v]));
        }

        for (int to = 0; to < n; ++to) {
            double dist = distance(v, to);
            if (dist < minEdge[to]) {
                minEdge[to] = dist;
                selectedEdge[to] = v;
            }
        }
    }

    printf("%f", res);
    return 0;
}