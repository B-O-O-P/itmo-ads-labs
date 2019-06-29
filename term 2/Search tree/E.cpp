#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;

struct node {
    long long key;
    long long sum;
    long long min, max;
    long long height;
    node* left;
    node* right;

    node(long long k) {
        key = k;
        min = k;
        max = k;
        sum = 0;
        height = 1;
        left = nullptr;
        right = nullptr;
    }


    long long get_height_left() {
        if (left == nullptr) {
            return 0;
        } else {
            return left->height;
        }
    }

    long long get_height_right() {
        if (right == nullptr) {
            return 0;
        } else {
            return right->height;
        }
    }

    long long get_balance() {
        return get_height_right() - get_height_left();
    }

    long long get_sum_left() {
        if (left) {
            return left->sum;
        }
        return 0;
    }

    long long get_sum_right() {
        if (right) {
            return right->sum;
        }
        return 0;
    }

    long long get_min_left() {
        if (left) {
            return left->min;
        }
        return LLONG_MAX;
    }

    long long get_min_right() {
        if (right) {
            return right->min;
        }
        return LLONG_MAX;
    }

    long long get_max_left() {
        if (left) {
            return left->max;
        }
        return LLONG_MIN;
    }

    long long get_max_right() {
        if (right) {
            return right->max;
        }
        return LLONG_MIN;
    }

    long long recalc_min_max() {
        this->min = std::min(std::min(get_min_left(), get_min_right()), key);
        this->max = std::max(std::max(get_max_left(), get_max_right()), key);
    }

    long long recalc_sum() {
        sum = get_sum_left() + get_sum_right();
        if (left) sum += left->key;
        if (right) sum += right->key;
    }

    void recalc() {
        height = 1 + std::max(this->get_height_left(), this->get_height_right());
    }
};

node* find(node* cur_node, int val) {
    if (cur_node == nullptr || cur_node->key == val) {
        return cur_node;
    }

    if (cur_node->key < val) {
        return find(cur_node->right, val);
    } else {
        return find(cur_node->left, val);
    }
}

bool exists(node* cur_node, long long val) {
    return find(cur_node, val) != nullptr;
}

node* right_rotate(node* cur_node) {
    node* left = cur_node->left;

    cur_node->left = left->right;
    left->right = cur_node;

    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();

    left->recalc();
    left->recalc_sum();
    left->recalc_min_max();

    return left;
}

node* left_rotate(node* cur_node) {
    node* right = cur_node->right;

    cur_node->right = right->left;
    right->left = cur_node;

    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();

    right->recalc();
    right->recalc_sum();
    right->recalc_min_max();

    return right;
}

node* rebalance(node* cur_node) {
    if (cur_node->get_balance() == 2) {
        if (cur_node->right->get_balance() < 0) {
            cur_node->right = right_rotate(cur_node->right);
        }
        return left_rotate(cur_node);
    }
    if (cur_node->get_balance() == -2) {
        if (cur_node->left->get_balance() > 0) {
            cur_node->left = left_rotate(cur_node->left);
        }
        return right_rotate(cur_node);
    }
    return cur_node;
}

node* insert(node* cur_node, long long new_key) {
    if (cur_node == nullptr) {
        return new node(new_key);
    }

    if (new_key < cur_node->key) {
        cur_node->left = insert(cur_node->left, new_key);
    } else {
        cur_node->right = insert(cur_node->right, new_key);
    }
    cur_node->recalc();
    cur_node->recalc_sum();
    cur_node->recalc_min_max();

    return rebalance(cur_node);
}

node* insert_node(node* cur_node, long long new_key) {
    if (exists(cur_node, new_key)) {
        return cur_node;
    }
    return insert(cur_node, new_key);
}


long long sum(node* cur_node, long long l, long long r) {
    if (cur_node == nullptr) {
        return 0;
    }

    if (cur_node->key > r) {
        return sum(cur_node->left, l, r);
    }

    if (cur_node->key < l) {
        return sum(cur_node->right, l, r);
    }

    if (cur_node->left == nullptr && cur_node->right == nullptr) {
        return cur_node->key;
    }

    if (cur_node->min >= l && cur_node->max <= r) {
        return cur_node->sum + cur_node->key;
    }
    return sum(cur_node->left, l, r) + sum(cur_node->right, l, r) + cur_node->key;
}

const long long TEN = 1000000000;

int main() {
    node* root = nullptr;
    char prev = '+';
    long long res = 0;
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == '+') {
            long long x;
            cin >> x;

            if (prev == '?') {
                root = insert_node(root, (x + res) % TEN);
            } else {
                root = insert_node(root, x);
            }
        } else {
            long long l, r;
            cin >> l >> r;

            res = sum(root, l, r);
            cout << res << endl;
        }
        prev = c;
    }

    return 0;
}