#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Automata {
    Automata() {
        nodes.emplace_back();
    }

    struct Node {
        int next[26];
        vector<int> terminant;

        int sLink;
        int ssLink;
    };

    vector <Node> nodes;
    size_t size = 0;

    void add(const string& s) {
        int cur = 0;

        for (char i : s) {
            int nextC = i - 'a';

            if (!nodes[cur].next[nextC]) {
                nodes.emplace_back();
                nodes[cur].next[nextC] = (int) nodes.size() - 1;
            }

            cur = nodes[cur].next[nextC];
        }

        nodes[cur].terminant.push_back(size++);
    }

    void build() {
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < 26; ++i) {
                if (!nodes[cur].next[i]) {
                    nodes[cur].next[i] = nodes[nodes[cur].sLink].next[i];
                } else {
                    int next = nodes[cur].next[i];

                    if (cur) {
                        nodes[next].sLink = nodes[nodes[cur].sLink].next[i];
                        nodes[next].ssLink = !nodes[nodes[next].sLink].terminant.empty() ? nodes[next].sLink
                                                                                         : nodes[nodes[next].sLink].ssLink;
                    }

                    q.push(next);
                }
            }
        }
    }

    vector<bool> findOccur(string& t) {
        vector<bool> occur(size);
        vector<bool> found(nodes.size());

        int cur = 0;
        for (char i : t) {
            cur = nodes[cur].next[i - 'a'];

            int tmp = cur;

            while (!found[tmp]) {
                if (!nodes[tmp].terminant.empty()) {
                    for (auto&& ends : nodes[tmp].terminant)
                        occur[ends] = true;
                }

                found[tmp] = true;
                tmp = nodes[tmp].ssLink;
            }
        }
        return occur;
    }
};

Automata a;
int n;


int main() {
    freopen("search4.in", "r", stdin);
    freopen("search4.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    string s, t;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        a.add(s);
    }

    cin >> t;
    a.build();

    vector<bool> ans = a.findOccur(t);

    for (auto&& an : ans) {
        cout << (an ? "YES\n" : "NO\n");
    }

    return 0;
}