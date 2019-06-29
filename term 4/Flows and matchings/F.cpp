#include <iostream>
#include <vector>
#include <cmath>

const double MAXTIME = 2000.0;
size_t n;
std::vector<std::vector<int>> graph;
std::vector<int> matching;
std::vector<char> used;

struct Point {
    int x;
    int y;
};
std::vector<Point> itemPoints;
std::vector<Point> destinationPoints;

std::vector<int> speeds;
double minTime;

double getTime(int itemNum, int dNum) {
    return std::sqrt(
            (itemPoints[itemNum].x - destinationPoints[dNum].x) * (itemPoints[itemNum].x - destinationPoints[dNum].x)
            + (itemPoints[itemNum].y - destinationPoints[dNum].y) * (itemPoints[itemNum].y - destinationPoints[dNum].y)
    ) / speeds[itemNum];
}

bool kuhn(int u) {
    if (used[u]) {
        return false;
    }
    used[u] = true;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        double edgeTime = getTime(u, v);
        if (edgeTime <= minTime) {
            if (matching[v] == -1 || kuhn(matching[v])) {
                matching[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool isComplete() {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (matching[i] != -1) {
            count++;
        }
    }
    return count == n;
}

void buildMatching() {
    matching.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        used.assign(n, false);
        kuhn(i);
    }
}

void kuhnBinSearch() {
    minTime = MAXTIME;
    double left = 0;
    double right = MAXTIME;
    while (right - left > 0.0001/2) {
        minTime = (left + right) / 2;
        buildMatching();
        if (isComplete()) {
            right = minTime;
        } else {
            left = minTime;
        }
    }
}


int main() {
    std::cin >> n;
    graph.resize(n);

    for (int i = 0; i < n; ++i) {
        int x, y, speed;

        std::cin >> x >> y >> speed;

        itemPoints.push_back({x, y});
        speeds.push_back(speed);

        for (int j = 0; j < n; ++j) {
            graph[i].push_back(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        int x, y;

        std::cin >> x >> y;

        destinationPoints.push_back({x, y});
    }

    kuhnBinSearch();
    std::cout << minTime << "\n";
    return 0;
}