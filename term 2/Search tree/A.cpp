#include <iostream>

using namespace std;

struct Node {
    long long x;
    int y;
    Node* l;
    Node* r;

    Node(long long nx) {
        x = nx;
        y = rand() * rand();
        l = nullptr;
        r = nullptr;
    }
};

void split(Node* t, Node*& l, Node*& r, long long x) {
    if (t == nullptr) {
        l = nullptr;
        r = nullptr;
        return;
    }

    if (t->x < x) {
        split(t->r, t->r, r, x);
        l = t;
    } else {
        split(t->l, l, t->l, x);
        r = t;
    }
};

void merge(Node*& t, Node* l, Node* r) {
    if (l == nullptr || r == nullptr) {
        if (r == nullptr) t = l;
        else t = r;
        return;
    }

    if (l->y > r->y) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
}

void insert(Node*& t, Node* v) {
    if (t == nullptr) {
        t = v;
        return;
    }

    if (t->y > v->y) {
        if (v->x < t->x)
            insert(t->l, v);
        else insert(t->r, v);
        return;
    }

    split(t, v->l, v->r, v->x);
    t = v;
}

void remove(Node*& t, long long x) {
    if (t == nullptr) return;

    if (x < t->x) {
        remove(t->l, x);
    } else if (x > t->x) {
        remove(t->r, x);
    } else {
        merge(t, t->l, t->r);
    }
}

bool exists(Node*& t, long long x) {
    if (t == nullptr) return false;

    if (x == t->x) return true;

    if (x < t->x) {
        return exists(t->l, x);
    } else return exists(t->r, x);
}


Node* prev(Node*& t, long long x) {
    Node* cur = t, * succ = nullptr;

    while (cur != nullptr) {
        if (cur->x < x) {
            succ = cur;
            cur = cur->r;
        } else {
            cur = cur->l;
        }
    }

    return succ;
}

Node* next(Node*& t, long long x) {
    Node* cur = t, * succ = nullptr;

    while (cur != nullptr) {
        if (cur->x > x) {
            succ = cur;
            cur = cur->l;
        } else {
            cur = cur->r;
        }
    }
    return succ;
}

int main() {
    string s;
    long long x;
    Node* v;
    Node* t = nullptr;

    while (cin >> s >> x) {
        if (s[0] == 'i') {
            v = new Node(x);
            if (!exists(t, x))insert(t, v);
            continue;
        }
        if (s[0] == 'e') {
            if (exists(t, x))cout << "true";
            else cout << "false";
            cout << "\n";
            continue;
        }
        if (s[0] == 'd') {
            if (exists(t, x))remove(t, x);
            continue;
        }
        if (s[0] == 'n') {
            v = next(t, x);
            if (v == nullptr) cout << "none";
            else cout << v->x;
            cout << "\n";
            continue;
        }
        if (s[0] == 'p') {
            v = prev(t, x);
            if (v == nullptr) cout << "none";
            else cout << v->x;
            cout << "\n";
        }
    }

    return 0;
}