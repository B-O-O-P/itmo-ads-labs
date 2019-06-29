#include <iostream>

using namespace std;

const int MIN = -1000000001;

struct Node {
    int x;
    int y;
    int size;
    Node* l;
    Node* r;

    Node(int nx) {
        x = nx;
        y = rand();
        l = nullptr;
        r = nullptr;
        size = 1;
    }
};

int size(Node*& t) {
    return t != nullptr ? t->size : 0;
}

void updateSize(Node*& t) {
    if (t != nullptr) {
        t->size = 1 + size(t->l) + size(t->r);
    }

}

void split(Node* t, Node*& l, Node*& r, int x) {
    if (t == nullptr) {
        l = nullptr;
        r = nullptr;
    } else if (t->x > x) {
        split(t->l, l, t->l, x);
        r = t;
    } else {
        split(t->r, t->r, r, x);
        l = t;
    }
    updateSize(t);
};

void merge(Node*& t, Node* l, Node* r) {
    if (l == nullptr || r == nullptr) {
        t = r ? r : l;
    } else if (l->y > r->y) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    updateSize(t);
}

void insert(Node*& t, Node* v) {
    if (t == nullptr) {
        t = v;
    } else if (t->y < v->y) {
        split(t, v->l, v->r, v->x);
        t = v;
    } else {
        insert(v->x < t->x ? t->l : t->r, v);
    }
    updateSize(t);
}

void remove(Node*& t, int x) {
    if (t->x == x)
        merge(t, t->l, t->r);
    else
        remove(x < t->x ? t->l : t->r, x);
    updateSize(t);
}


int findKthMax(Node*& t, int k) {
    int leftsize = size(t->l);
    if (leftsize == k) {
        return t->x;
    } else if (leftsize > k)
        return findKthMax(t->l, k);
    else {
        k -= leftsize + 1;
        return findKthMax(t->r, k);
    }
}

void printTree(Node*& t) {
    if (t == nullptr) return;
    printTree(t->l);
    printf("(%d,%d)\t", t->x, t->size);
    printTree(t->r);
}

int main() {
    int s;
    int x;
    int n;
    int length = 0;
    Node* v;
    Node* t = nullptr;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &x);
        if (s == 1) {
            v = new Node(x);
            insert(t, v);
            length++;
            continue;
        }
        if (s == 0) {
            printf("%d\n", findKthMax(t, length - x));
            continue;
        }
        if (s == -1) {
            remove(t, x);
            length--;
        }
    }

    return 0;
}