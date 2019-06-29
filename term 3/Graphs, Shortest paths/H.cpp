#include<iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1000000 + 500;
int d[maxn];

struct Node {
    int x, y;

    Node() {};

    Node(int xx, int yy) : x(xx), y(yy) {};
};

vector<Node> e[maxn];
int inq[maxn];

int main() {
    freopen("dwarf.in", "r", stdin);
    freopen("dwarf.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);

    for (int i = 1; i <= m; i++) {
        int a, u, v;
        scanf("%d%d%d", &a, &u, &v);
        e[u].push_back(Node(v, a));
        e[v].push_back(Node(u, a));
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        inq[i] = 1;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inq[now] = 0;
        for (int i = 0; i < e[now].size(); i++) {
            Node temp = e[now][i];
            if (d[temp.y] > d[temp.x] + d[now]) {
                d[temp.y] = d[temp.x] + d[now];
                if (!inq[temp.y])
                    q.push(temp.y);
                inq[temp.y] = 1;
            }
        }
    }

    printf("%d\n", d[1]);

}
