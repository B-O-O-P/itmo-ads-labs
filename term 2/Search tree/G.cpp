#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int y;
    int size;
    int x;

    Node* l;
    Node* r;
};

Node* newNode(int value) {
    Node* res = new Node;
    res->y = rand() * rand();
    res->size = 1;
    res->x = value;
    res->l = res->r = nullptr;
    return res;
}

int getSize(Node* t) {
    if (t == nullptr)
        return 0;
    return t->size;
}

void updateSize(Node* t) {
    if (t == nullptr) return;;
    t->size = 1 + getSize(t->l) + getSize(t->r);
}

Node* merge(Node* t1, Node* t2) {
    if (t1 == nullptr) {
        return t2;
    }

    if (t2 == nullptr) {
        return t1;
    }

    if (t1->y > t2->y) {
        t1->r = merge(t1->r, t2);
        updateSize(t1);
        return t1;
    } else {
        t2->l = merge(t1, t2->l);
        updateSize(t2);
        return t2;
    }
}

void split(Node* t, int x, Node*& t1, Node*& t2) {
    if (t == nullptr) {
        t1 = t2 = nullptr;
        return;
    }

    if (getSize(t->l) < x) {
        split(t->r, x - getSize(t->l) - 1, t->r, t2);
        t1 = t;
    } else {
        split(t->l, x, t1, t->l);
        t2 = t;
    }
    updateSize(t);
}

Node* build(const vector<int>& v) {
    Node* result = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        result = merge(result, newNode(v[i]));
    }
    return result;
}

Node* tostart(Node* t, int l, int r) {
    Node* t1, * t2, * t3, * t4;
    split(t, r + 1, t1, t2);
    split(t1, l, t3, t4);
    return merge(merge(t4, t3), t2);
}


void printTree(Node* t) {
    if (t == nullptr)return;
    printTree(t->l);
    cout << t->x << " ";
    printTree(t->r);
}

int main() {
    int n, m;
    int l, r;
    vector<int> a;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
        a.push_back(i + 1);

    Node* t = build(a);

    for (int i = 0; i < m; i++) {
        cin >> l;
        cin >> r;
        tostart(t, l - 1, r - 1);
    }

    printTree(t);

    return 0;
}