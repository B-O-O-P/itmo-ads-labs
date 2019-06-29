#include <iostream>
#include <climits>
#include <vector>

struct Node {
    int size;
    int p;
    int data;
    bool zero;

    Node* left, * right;

    Node(int data = 0, bool isZero = true) {
        this->data = data;
        this->zero = isZero;
        p = rand() * rand();
        size = 1;
        left = right = nullptr;
    }
};

struct Treap {
    Node* root = nullptr;
    int num = 0;

    Node* merge(Node* l, Node* r) {
        if (l == nullptr) return r;
        if (r == nullptr) return l;

        if (l->p > r->p) {
            l->right = merge(l->right, r);
            updateSize(l);
            updateZero(l);
            return l;
        } else {
            r->left = merge(l, r->left);
            updateSize(r);
            updateZero(r);
            return r;
        }
    }

    void split(Node* t, int key, Node*& l, Node*& r) {
        if (t == nullptr) {
            l = r = nullptr;
            return;
        }
        if (getSize(t->left) < key) {
            split(t->right, key - getSize(t->left) - 1, t->right, r);
            l = t;
        } else {
            split(t->left, key, l, t->left);
            r = t;
        }
        updateSize(t);
        updateZero(t);
    }

    int getSize(Node* t) {
        if (t == nullptr)return 0;
        else return t->size;
    }

    void updateSize(Node* t) {
        t->size = getSize(t->left) + getSize(t->right) + 1;
    }

    void updateZero(Node* t) {
        t->zero = getZero(t->left) || getZero(t->right) || (t->data == 0);
    }

    bool getZero(Node* t) {
        if (t == nullptr)return false;
        return t->zero;
    }


    Node* searchNull(Node* t, int& ind) {
        Node* cur = t;
        ind = getSize(cur->left);

        while (getZero(cur)) {
            if (cur->left != nullptr && getZero(cur->left)) {
                cur = cur->left;
                ind = ind - getSize(cur->right) - 1;
            } else if (getData(cur) == 0) {
                break;
            } else {
                cur = cur->right;
                ind += getSize(cur->left);
                ind++;
            }
        }

        return cur;
    }

    int getData(Node* t) {
        if (t == nullptr)return -1;
        return t->data;
    }

    void toArray(Node* node, std::vector<int>& a) {
        if (node) {
            toArray(node->left, a);
            a.push_back(getData(node));
            toArray(node->right, a);
        }
    }

    Node* remove(Node* r, int key) {
        Node* t1, * t2, * t3;
        split(r, key, t1, t2);
        split(t2, 1, t2, t3);
        r = merge(t1, t3);
        delete (t2);
        return r;
    }

    void build(int n) {
        for (int i = 0; i < n; ++i) {
            root = merge(new Node, root);
        }
    }


    void insert(int ind) {
        Node* l, * r, * z;
        int i;

        split(root, ind, l, r);
        z = searchNull(r, i);
        if (z != nullptr && z->data == 0) {
            r = remove(r, i);
        }

        root = merge(merge(l, new Node(++num, false)), r);
    }

};

int main() {
    int n, j, m;
    scanf("%d %d", &n, &m);

    Treap tree;
    tree.build(m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &j);
        tree.insert(j - 1);
    }

    std::vector<int> ans;
    tree.toArray(tree.root, ans);
    while (!ans.empty() && ans.back() == 0)
        ans.pop_back();

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}