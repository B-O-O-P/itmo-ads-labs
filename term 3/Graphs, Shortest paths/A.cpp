#include <iostream>
#include <vector>


using namespace std;
int n;

void Floyd(vector<vector<int>>& graph) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    cin >> n;

    vector<vector<int>> graph;
    graph.resize(n);

    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    Floyd(graph);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}