#include <iostream>

using namespace std;

const long long MAX = 1000000001;

int n;

struct Node {
    int maxx;
    int sum;
    int set;
    int id;
    Node* l;
    Node* r;

    Node() {
        l = nullptr;
        r = nullptr;
        maxx = 0;
        sum = 0;
        set = MAX;
        id = 0;
    }

    explicit Node(int index) {
        l = nullptr;
        r = nullptr;
        maxx = 0;
        sum = 0;
        set = MAX;
        id = index;
    }

    Node(Node* x, Node* y) {
        l = x;
        r = y;
    }

    ~Node() {
        delete l;
        delete r;
    }

    void updatemax() {
        maxx = max(l->maxx, r->maxx + l->sum);
        sum = l->sum + r->sum;
    }
};

Node t;

void push(Node* v) {
    v->l->set = v->set;
    v->r->set = v->set;
}

void getChild(Node* v, int l, int r) {
    if (v->l == nullptr) {
        int leftid = v->id * 2 + 1;
        int rightid = v->id * 2 + 2;
        v->l = new Node(leftid);
        v->r = new Node(rightid);
    }

    if (v->set == MAX)
        return;

    v->sum = v->set * (r - l + 1);
    v->maxx = v->sum;
    if (l != r) {
        push(v);
    }
    v->set = MAX;
}

void set(Node* v, int l, int r, int tl, int tr, int value) {
    getChild(v, l, r);
    if (tl > r || l > tr)
        return;

    if (l >= tl && r <= tr) {
        v->set = value;
        getChild(v, l, r);
        return;
    }

    int tm = l + (r - l) / 2;

    set(v->l, l, tm, tl, tr, value);
    set(v->r, tm + 1, r, tl, tr, value);

    v->updatemax();
}

long long get(Node* v, int l, int r, int height) {
    getChild(v, l, r);

    if (l == r)
        return r;

    int m = l + (r - l) / 2;
    getChild(v->l, l, m);

    if (v->l->maxx <= height) {
        getChild(v->r, m + 1, r);
        height -= v->l->sum;
        return get(v->r, m + 1, r, height);
    } else {
        return get(v->l, l, m, height);
    }
}

int main() {
    scanf("%d", &n);
    char s;

    while (scanf("%s", &s) != EOF) {
        if (s == 'E')
            return 0;

        if (s == 'I') {
            int a, b, D;
            scanf("%d %d %d", &a, &b, &D);
            a -= 1;
            b -= 1;
            set(&t, 0, n, a, b, D);
        }

        if (s == 'Q') {
            int height;
            scanf("%d", &height);
            printf("%lld\n", get(&t, 0, n, height));
        }
    }
    return 0;
}