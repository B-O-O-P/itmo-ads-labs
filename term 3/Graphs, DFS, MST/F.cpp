#include <iostream>
#include <vector>
#include <map>
#include <set>


using namespace std;

vector<vector<int>> graph, transgraph;
vector<int> order, numberOfComponent;
vector<bool> used;
set <pair<int, int>> noMultEdges;
int n, m, col;

void dfsOne(int v) {
    used[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (!used[to])
            dfsOne(to);
    }
    order.push_back(v);
}

void dfsTwo(int v) {
    used[v] = true;
    numberOfComponent[v] = col;
    for (int i = 0; i < transgraph[v].size(); ++i) {
        int to = transgraph[v][i];
        if (!used[to])
            dfsTwo(to);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    graph.resize(n);
    transgraph.resize(n);
    used.resize(n);
    numberOfComponent.resize(n);

    for (int i = 0; i < m; ++i) {
        int beg, end;
        scanf("%d %d", &beg, &end);
        graph[beg - 1].push_back(end - 1);
        transgraph[end - 1].push_back(beg - 1);
    }

    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfsOne(i);
        }
    }

    used.assign(n, false);
    col = 1;
    for (int i = 0; i < n; ++i) {
        int v = order[n - 1 - i];
        if (!used[v]) {
            dfsTwo(v);
            col++;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph[i].size(); j++) {
            int to = graph[i][j];
            if (numberOfComponent[i] != numberOfComponent[to])
                noMultEdges.insert(make_pair(numberOfComponent[i], numberOfComponent[to]));
        }
    }


    printf("%d", noMultEdges.size());
    return 0;
}