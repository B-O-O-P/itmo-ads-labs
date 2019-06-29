#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>

using namespace std;


const int MAXN = 5555;
const int MAXNM = 100000;
const int INF = 1000000000;

struct Edge {
    int u, v, cap, flow, next;
};
vector<Edge> edges;
int currentCapacity;
vector<int> h, d, cur;
vector<bool> visited;

void add(int u, int v, int cap) {
    edges[currentCapacity] = {u, v, cap, 0, h[u]};
    h[u] = currentCapacity++;
    edges[currentCapacity] = {v, u, 0, 0, h[v]};
    h[v] = currentCapacity++;
}


bool bfs(int s, int t) {
    queue<int> q;
    visited.assign(MAXN, false);
    d[s] = 0;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;

            if (!visited[v] && edges[i].cap > edges[i].flow) {
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return visited[t];
}

int dfs(int u, int a, int t) {
    if (u == t || a == 0) {
        return a;
    }
    int flow = 0;
    for (int &i = cur[u]; i != -1; i = edges[i].next) {
        int v = edges[i].v, &ef = edges[i].flow, cap = edges[i].cap;
        if (d[v] == d[u] + 1) {
            int pushed = dfs(v, min(a, edges[i].cap - edges[i].flow), t);
            if (pushed) {
                a -= pushed;
                flow += pushed;
                edges[i].flow += pushed;
                edges[i ^ 1].flow -= pushed;
                if (a == 0) break;
            }
        }
    }
    return flow;
}

int algoDinic(int s, int t, int n, int need) {
    int flow = 0;
    while (bfs(s, t)) {
        for (int i = 0; i < n; i++) {
            cur[i] = h[i];
        }
        flow += dfs(s, need - flow, t);
        if (flow == need) {
            return flow;
        }
    }
    return flow;
}

int main() {
    freopen("bring.in", "r", stdin);
    freopen("bring.out", "w", stdout);
    size_t n, m, k, s, t;

    cin >> n >> m >> k >> s >> t;
    s--;
    t--;

    edges.resize(MAXNM);
    h.resize(MAXN);
    d.resize(MAXN);
    cur.resize(MAXN);
    visited.resize(MAXN);

    vector<int> u(m), v(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    h.assign(MAXN, -1);
    currentCapacity = 0;
    int day = 1;
    int currentFLow = 0;


    while (true) {
        for (int i = 0; i < n; i++)
            add((day - 1) * n + i, day * n + i, INF);
        for (int i = 0; i < m; i++) {
            add((day - 1) * n + u[i], day * n + v[i], 1);
            add((day - 1) * n + v[i], day * n + u[i], 1);
        }

        currentFLow += algoDinic(s, day * n + t, day * n + n, k - currentFLow);

        if (currentFLow == k) break;
        day++;
    }


    cout << day << "\n";
    vector<int> location(k, s);
    for (int d = 1, id = n * 2; d <= day; d++, id += n * 2) {
        vector<int> moved(k, 0);
        vector<int> A, B;
        for (int i = 0; i < m; i++) {
            int firstFlow = edges[id].flow;
            id += 2;
            int secondFlow = edges[id].flow;
            id += 2;
            if (firstFlow == 1 && !secondFlow) {
                A.push_back(u[i]);
                B.push_back(v[i]);
            }
            if (!firstFlow && secondFlow == 1) {
                A.push_back(v[i]);
                B.push_back(u[i]);
            }
        }
        cout << A.size();
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < k; j++)
                if (!moved[j] && location[j] == A[i]) {
                    moved[j] = 1;
                    cout << " " << j + 1 << " " << B[i] + 1;
                    location[j] = B[i];
                    break;
                }
        }
        cout << "\n";
    }
    return 0;
}