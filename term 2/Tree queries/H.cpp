#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX = 1000001;

vector<vector<int>> graph;
int color[MAX], res[MAX];
set<int> sett[MAX];

void add(set<int>& a, set<int>& b) {
    if (a.size() < b.size())a.swap(b);

    for (auto i = b.begin(); i != b.end(); i++) {
        a.insert(*i);
    }
    b.clear();
}

void dfs(int v) {
    int t;
    sett[v].insert(color[v]);

    for (int i = 0; i < graph[v].size(); i++) {
        t = graph[v][i];
        dfs(t);
        add(sett[v], sett[t]);
    }

    res[v] = sett[v].size();
}

int main() {
    size_t n;
    scanf("%d", &n);
    graph.resize(n + 1);

    for (int i = 1; i < n + 1; i++) {
        int parent, col;
        scanf("%d %d", &parent, &col);
        graph[parent].push_back(i);
        color[i] = col;
    }
    dfs(0);

    for (int i = 1; i < n + 1; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}