#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> x, y, num;

struct Node {
    int x;
    int y;
    int number;
    Node* l;
    Node* r;
    Node* p;

    Node(int xx, int yy, int num) {
        x = xx;
        y = yy;
        number = num;
        l = nullptr;
        r = nullptr;
        p = nullptr;
    }
};

Node* t;
vector<Node*> xyn;
vector<Node*> originals;

bool compare(Node*& a, Node*& b) {
    return a->x < b->x;
}

void printNum(Node* t, int num) {
    if (t == nullptr)
        return;

    if (t->number == num) {
        if (t->p == nullptr) cout << 0;
        else cout << t->p->number;
        cout << " ";
        if (t->l == nullptr) cout << 0;
        else cout << t->l->number;
        cout << " ";
        if (t->r == nullptr) cout << 0;
        else cout << t->r->number;
        cout << "\n";
    } else {
        printNum(t->l, num);
        printNum(t->r, num);
    }
}

void build(Node*& t) {
    t = xyn[0];
    Node* last = t;

    for (int i = 1; i < n; i++) {
        if (last->y < y[i]) {
            last->r = xyn[i];
            last->r->p = last;
            last = last->r;
        } else {
            Node* cur = last;
            while (cur->p != nullptr && cur->y > xyn[i]->y)
                cur = cur->p;
            if (cur->y > xyn[i]->y) {
                last = xyn[i];
                last->l = cur;
                cur->p = last;
            } else {
                last = xyn[i];
                last->l = cur->r;
                cur->r->p = last;
                last->p = cur;
                cur->r = last;
            }
        }
    }

    while (last->p != nullptr)
        last = last->p;
    t = last;
}

int main() {
    cin >> n;
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        Node* e = new Node(a, b, i + 1);
        xyn.push_back(e);
        originals.push_back(e);
    }

    sort(xyn.begin(), xyn.end(), compare);

    for (int i = 0; i < n; i++) {
        x.push_back(xyn[i]->x);
        y.push_back(xyn[i]->y);
        num.push_back(xyn[i]->y);
    }

    build(t);

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        Node* cur = originals[i];
        if (cur->p == nullptr) cout << 0;
        else cout << cur->p->number;
        cout << " ";
        if (cur->l == nullptr) cout << 0;
        else cout << cur->l->number;
        cout << " ";
        if (cur->r == nullptr) cout << 0;
        else cout << cur->r->number;
        cout << "\n";
    }

    return 0;
}