#include <iostream>
#include <vector>


const int MAXN = 101;
const int MAXM = 101;

size_t n, m;
int type;

struct Edge {
    int to;
    int x, y;
    int colour = 0;

    Edge* reversed;

    Edge(int to, int x, int y, int colour) : to(to), x(x), y(y), colour(colour) {}
};

struct Square {
    int diagonalType;
    int x, y;
};
std::vector<std::vector<Edge*>> edges;
std::vector<std::vector<int>> table;
std::vector<char> used;
std::vector<Square> answer;

void addEdge(int from, int to, int i, int j) {
    Edge* edge = new Edge(to, i, j, 1);
    Edge* reversed = new Edge(from, i, j, 0);

    edge->reversed = reversed;
    reversed->reversed = edge;

    edges[from].push_back(edge);
    edges[to].push_back(reversed);
}

bool kuhn(int v) {
    if (v == 4 * (n + m)) {
        return true;
    }
    used[v] = true;

    for (Edge* edge : edges[v]) {
        if (edge->colour == 1 && !used[edge->to] && kuhn(edge->to)) {
            edge->colour = 0;
            edge->reversed->colour = 1;
            return true;
        }
    }

    return false;
}

std::vector<Square> getCover() {
    edges.assign(4 * (MAXM + MAXN), std::vector<Edge*>());
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == 1) {
                addEdge(i - j + n + m, i + j + 2 * (m + n), i + 1, j + 1);
            }
        }
    }

    for (int i = 1; i < 2 * (n + m); ++i) {
        addEdge(0, i, i + 1, i + 1);
    }

    for (int i = 2 * (n + m); i < 4 * (n + m); ++i) {
        addEdge(i, 4 * (n + m), i + 1, i + 1);
    }

    while (true) {
        used.assign(4 * (MAXN + MAXM), false);
        if (!kuhn(0)) {
            break;
        }
        count++;
    }

    std::vector<Square> res(count, {0, 0, 0});
    int t = 0;

    for (int i = 0; i < 2 * (n + m); ++i) {
        if (!used[i]) {
            for (Edge* edge : edges[i]) {
                if (edge->to != 0) {
                    res[t] = {2, edge->x, edge->y};
                    t++;
                    break;
                }
            }
        }
    }

    for (int i = 2 * (n + m); i < 4 * (n + m); ++i) {
        if (used[i]) {
            for (Edge* edge : edges[i]) {
                if (edge->to != 4 * (n + m)) {
                    res[t] = {1, edge->x, edge->y};
                    t++;
                    break;
                }
            }
        }
    }

    return res;
}

void swapColour() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            table[i][j] = 1 - table[i][j];
        }
    }
}

void solve() {
    std::vector<Square> firstCover = getCover();
    swapColour();
    std::vector<Square> secondCover = getCover();

    if (secondCover.size() > firstCover.size()) {
        answer = firstCover;
        type = 0;
    } else {
        answer = secondCover;
        type = 1;
    }
}

int main() {
    std::cin >> n >> m;
    edges.resize(4 * (MAXM + MAXN), std::vector<Edge*>());
    table.resize((MAXN), std::vector<int>(MAXM));
    used.resize(4 * (MAXM + MAXM));

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < m; ++j) {
            if (line[j] == 'W') {
                table[i][j] = (i + j) % 2;
            } else {
                table[i][j] = abs((i + j) % 2 - 1);
            }
        }
    }

    solve();

    std::cout << answer.size() << "\n";

    for (Square& square : answer) {
        std::cout << square.diagonalType << " "
                  << square.x << " " << square.y << " "
                  << (((square.x + square.y) % 2 == type) ? 'W' : 'B') << "\n";
    }
    return 0;
}