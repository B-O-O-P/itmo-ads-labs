#include <iostream>
#include <vector>
#include <queue>
#include <climits>

const int MAXN = 110;
const int MAXM = 110;
const int INF = INT_MAX;
size_t n, m;
int t;
int s;
long long maxFlow;

struct Edge {
    int from, to;//number of points
    long long c, f;
    int x = -1, y = -1;//coords on map
    bool rev = true;

    Edge* reversed = nullptr;

    Edge(int from, int to, long long c, long long f) : from(from), to(to), c(c), f(f) {

    }

    Edge(int from, int to, long long c, long long f, int x, int y, bool rev) : from(from), to(to), c(c), f(f), x(x),
                                                                               y(y), rev(rev) {

    }
};

std::vector<std::vector<Edge*>> edges(MAXN * MAXM, std::vector<Edge*>(0));
std::vector<int> d(MAXN * MAXM, -1);
std::vector<int> del(MAXM * MAXN, 0);
std::vector<std::vector<char>> kingdom(MAXN, std::vector<char>(MAXM));

int getInId(int i, int j) {
    return i * m + j;
}

int getOutId(int i, int j) {
    return i * m + j + n * m;
}

void addEdge(int v, int u, long long c) {
    edges[v].push_back(new Edge(v, u, c, 0));
    edges[u].push_back(new Edge(u, v, 0, 0));
    edges[u].back()->reversed = edges[v].back();
    edges[v].back()->reversed = edges[u].back();
}

void addDirEdge(int v, int u, long long c, int x, int y, bool rev) {
    edges[v].push_back(new Edge(v, u, c, 0, x, y, rev));
}

bool bfs() {
    d.assign(MAXN * MAXM, -1);
    std::queue<int> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (Edge* to : edges[v]) {
            if (d[to->to] == -1 && to->f < to->c) {
                d[to->to] = d[v] + 1;
                q.push(to->to);
            }
        }
    }

    return d[t] != -1;
}

long long dfs(int v, long long minC) {
    if (v == t) {
        return minC;
    }

    for (int i = del[v]; i < edges[v].size(); ++i) {
        Edge* to = edges[v][i];

        if (to->f < to->c && d[to->to] == d[v] + 1) {
            long long pushed = dfs(to->to, std::min(minC, to->c - to->f));
            if (pushed) {
                to->f += pushed;
                if (to->rev) {
                    to->reversed->f -= pushed;
                }
                return pushed;
            }
        }

        del[v] = i + 1;
    }
    return 0;
}

long long algoDinic() {
    while (bfs()) {
        del.assign(MAXM * MAXN, 0);
        while (true) {
            long long pushedFlow = dfs(s, INF);
            maxFlow += pushedFlow;
            if (!pushedFlow) {
                break;
            }
        }
    }
    return maxFlow;

}

std::vector<int> reached;
std::vector<bool> visited;

void dfs2(int v) {
    visited[v] = true;

    reached.push_back(v);
    for (Edge* e : edges[v]) {
        if (!visited[e->to]) {
            if (e->f < e->c) {
                dfs2(e->to);
            }
        }
    }
}

void findMinCut() {
    visited.assign(MAXN * MAXM, false);
    dfs2(s);

    for (int v : reached) {
        for (Edge* e : edges[v]) {
            if (!visited[e->to] && e->f == 1) {
                kingdom[e->x][e->y] = '+';
                break;
            }
        }
    }
}

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < m; ++j) {
            kingdom[i][j] = line[j];
            switch (kingdom[i][j]) {
                case '-':
                    addDirEdge(getInId(i, j), getOutId(i, j), INF, i, j, false);
                    break;
                case '.':
                    addDirEdge(getInId(i, j), getOutId(i, j), 1, i, j, false);
                    break;
                case '#':
                    addDirEdge(getInId(i, j), getOutId(i, j), 0, i, j, false);
                    break;
                case 'A':
                    s = getOutId(i, j);
                    break;
                case 'B':
                    t = getInId(i, j);
                    break;
                default:
                    break;
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            addEdge(getOutId(i, j), getInId(i + 1, j), INF);
            addEdge(getOutId(i + 1, j), getInId(i, j), INF);
            addEdge(getOutId(i, j), getInId(i, j + 1), INF);
            addEdge(getOutId(i, j + 1), getInId(i, j), INF);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        addEdge(getOutId(i, m - 1), getInId(i + 1, m - 1), INF);
        addEdge(getOutId(i + 1, m - 1), getInId(i, m - 1), INF);
    }

    for (int j = 0; j < m - 1; ++j) {
        addEdge(getOutId(n - 1, j), getInId(n - 1, j + 1), INF);
        addEdge(getOutId(n - 1, j + 1), getInId(n - 1, j), INF);
    }

    algoDinic();
    findMinCut();

    if (maxFlow >= INF) {
        std::cout << "-1";
    } else {
        std::cout << maxFlow << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << kingdom[i][j];
            }
            std::cout << "\n";
        }
    }
    return 0;
}