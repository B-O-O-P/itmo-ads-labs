#include <vector>
#include <iostream>
#include <list>

using namespace std;

const int INF = 1000000001;
int root, n, m;
long long res;

struct Edge {
    int from, to, w;

    Edge(int from, int to, int w) :
            from(from), to(to), w(w) {}
};

struct graphNode {
    int root, numberOfEdge, w;

    graphNode(int r, int num, int w) :
            root(r), numberOfEdge(num), w(w) {}
};

void dfs(int v, vector<bool>& used, vector<vector<graphNode>>& graph, bool zero) {
    if (!used[v]) {
        used[v] = true;
        for (graphNode& node : graph[v]) {
            if (node.w == 0 || !zero) {
                dfs(node.root, used, graph, zero);
            }
        }
    }
}

bool canBeSolved(vector<vector<graphNode>>* graph, bool zero) {
    vector<bool> used(graph->size(), false);

    dfs(root, used, *graph, zero);
    for (bool v : used) {
        if (!v)
            return false;
    }
    return true;
}

void dfsOut(int v, vector <vector<graphNode>>& graph, vector<bool>& used, list<int>& out) {
    if (!used[v]) {
        used[v] = true;
        for (graphNode& node : graph[v]) {
            if (node.w == 0)
                dfsOut(node.root, graph, used, out);
        }
        out.push_front(v);
    }
}

vector<vector<graphNode>>* getReversedGraph(vector <vector<graphNode>>& graph) {

    vector<vector<graphNode>>* res = new vector<vector<graphNode>>(graph.size());

    for (int i = 0; i < graph.size(); i++) {
        for (graphNode& node : graph[i]) {
            (*res)[node.root].push_back(graphNode(i, node.numberOfEdge, node.w));
        }
    }
    return res;
}

void paint(int v, int color, vector<vector<graphNode>>& graph, vector<int>& comp) {
    if (!comp[v]) {
        comp[v] = color;
        for (graphNode& node : graph[v]) {
            if (node.w == 0)
                paint(node.root, color, graph, comp);
        }
    }
}

vector<vector<graphNode>>* getReversedCondensation(vector<vector<graphNode>>& graph, vector<Edge>& edges) {
    vector<bool> marked(graph.size(), false);
    list<int> outTime;


    dfsOut(root, graph, marked, outTime);

    for (int i = 0; i < graph.size(); i++) {
        dfsOut(i, graph, marked, outTime);
    }


    vector<int> colors(graph.size(), 0);
    int color = 1;

    vector<vector<graphNode>>* condensation = getReversedGraph(graph);
    for (int& o : outTime) {
        if (!colors[o]) {
            paint(o, color++, *condensation, colors);
        }
    }
    delete condensation;

    root = colors[root];
    root--;
    color--;


    vector<vector<graphNode>>* newGraph = new vector<vector<graphNode>>(color);

    for (int i = 0; i < graph.size(); i++) {
        for (graphNode& node : graph[i]) {
            if (colors[i] != colors[node.root]) {
                (*newGraph)[colors[i] - 1].push_back(
                        graphNode(colors[node.root] - 1, node.numberOfEdge, node.w));
            }
        }
    }
    return newGraph;
}


void findMinWeight(vector<vector<graphNode>>* graph, vector<Edge>& edges) {

    for (int i = 0; i < graph->size(); ++i) {
        int minEdge = INF;

        for (graphNode& node : (*graph)[i]) {
            minEdge = min(minEdge, node.w);
        }

        for (graphNode& node : (*graph)[i]) {
            node.w -= minEdge;
        }

        if (i != root)
            res += minEdge;
    }


    if (!canBeSolved(getReversedGraph(*graph), true)) {
        vector <vector<graphNode>>* cond = getReversedCondensation(*graph, edges);
        return findMinWeight(cond, edges);
    }
}

int main() {
    root = 0;
    res = 0;

    scanf("%d %d", &n, &m);
    vector<vector<graphNode>>* graph = new vector<vector<graphNode>>(n);
    vector<vector<graphNode>>* reversedGraph = new vector<vector<graphNode>>(n);
    vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        int u, v;
        int w;

        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;

        edges.push_back(Edge(u, v, w));

        (*graph)[u].push_back(graphNode(v, i, w));
        (*reversedGraph)[v].push_back(graphNode(u, i, w));
    }

    if (canBeSolved(graph, false)) {
        printf("YES\n");
        findMinWeight(reversedGraph, edges);
        printf("%I64d", res);
    } else {
        printf("NO\n");
    }

    return 0;
}
