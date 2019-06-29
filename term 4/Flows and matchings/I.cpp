#include <iostream>
#include <vector>
#include <set>
#include <climits>

const int MAXN = 105;

size_t n;
int s, t;
long long maxFlow = 0;
const int INF = INT_MAX;

struct Edge {
    int from, to;//number of teams
    long long c, f{};
    int x = -1, y = -1;//coords of table
    bool rev = true;

    Edge* reversed = nullptr;

    Edge(int from, int to, long long c, long long f) : from(from), to(to), c(c), f(f) {

    }

    Edge(int from, int to, long long c, int x, int y, bool rev) : from(from), to(to), c(c), x(x), y(y), rev(rev) {

    }
};


std::vector<std::vector<Edge*>> edges(MAXN, std::vector<Edge*>(0));
std::vector<int> scores(MAXN);
std::vector<std::vector<char>> table(MAXN, std::vector<char>(MAXN, '0'));
std::vector<std::set<int>> play(MAXN, std::set<int>());
std::vector<int> get(MAXN, 0);
std::vector<bool> used(MAXN, false);

void addEdge(int v, int u, long long c) {
    edges[v].push_back(new Edge(v, u, c, 0));
    edges[u].push_back(new Edge(u, v, 0, 0));
    edges[u].back()->reversed = edges[v].back();
    edges[v].back()->reversed = edges[u].back();
}

long long dfs(int v, long long minC) {
    if (v == t) {
        return minC;
    }
    used[v] = true;

    for (Edge* to : edges[v]) {
        if (!used[to->to] && to->f < to->c) {
            long long pushed = dfs(to->to, std::min(minC, to->c - to->f));
            if (pushed) {
                to->f += pushed;
                to->reversed->f -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

long long algoDinic() {
    while (true) {
        used.assign(MAXN, false);
        long long pushed = dfs(s, INF);
        maxFlow += pushed;
        if (!pushed) {
            break;
        }
    }

    return maxFlow;
}

long long can(int team) {
    long long count = 0;
    for (int i : play[team]) {
        if (i > team) {
            count += 3;
        }
    }
    return count;
}

int main() {
    std::cin >> n;
    s = 0;
    t = n + 1;

    for (int i = 1; i <= n; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 1; j <= n; j++) {
            auto res = line[j - 1];
            table[i][j] = res;
            switch (res) {
                case 'W': {
                    scores[i] += 3;
                    break;
                }
                case 'w': {
                    scores[i] += 2;
                    break;
                }
                case 'L': {
                    scores[i] += 0;
                    break;
                }
                case 'l': {
                    scores[i] += 1;
                    break;
                }
                case '.': {
                    play[i].insert(j);
                    break;
                }
                default:break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int score;
        std::cin >> score;
        get[i] = std::max(0, score - scores[i]);
    }

    for (int i = 1; i <= n; ++i) {
        addEdge(s, i, can(i));
    }

    for (int i = 1; i <= n; ++i) {
        addEdge(i, t, get[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j : play[i]) {
            if (j > i) {
                addEdge(i, j, 3);
            }
        }
    }

    algoDinic();

    for (int i = 1; i <= n; ++i) {
        for (Edge* e : edges[i]) {
            if (e->to != t && e->to != s && i < e->to) {
                switch (e->f) {
                    case 0: {
                        table[i][e->to] = 'W';
                        table[e->to][i] = 'L';
                        break;
                    }
                    case 1: {
                        table[i][e->to] = 'w';
                        table[e->to][i] = 'l';
                        break;
                    }
                    case 2: {
                        table[i][e->to] = 'l';
                        table[e->to][i] = 'w';
                        break;
                    }
                    case 3: {
                        table[i][e->to] = 'L';
                        table[e->to][i] = 'W';
                        break;
                    }
                    default:break;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << table[i][j];
        }
        std::cout << "\n";
    }
    return 0;
}