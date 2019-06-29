#include <iostream>
#include <vector>

using namespace std;

int r;

struct Matrix2x2 {
public:
    long long a11;
    long long a21;
    long long a12;
    long long a22;

    Matrix2x2() {
        a11 = 0;
        a12 = 0;
        a21 = 0;
        a22 = 0;
    }

    Matrix2x2(const Matrix2x2& other) {
        a11 = other.a11;
        a12 = other.a12;
        a21 = other.a21;
        a22 = other.a22;
    }


    Matrix2x2(long long a, long long b, long long c, long long d) {
        a11 = a;
        a12 = b;
        a21 = c;
        a22 = d;
    }

    Matrix2x2 operator*(const Matrix2x2& v) {
        Matrix2x2 res = Matrix2x2((this->a11 * v.a11 + this->a12 * v.a21) % r,
                                  (this->a11 * v.a12 + this->a12 * v.a22) % r,
                                  (this->a21 * v.a11 + this->a22 * v.a21) % r,
                                  (this->a21 * v.a12 + this->a22 * v.a22) % r);
        return res;
    }
};

int n, m;

int getMiddle(int l, int r) {
    return l + (r - l) / 2;
}


vector <Matrix2x2> t;
vector <Matrix2x2> a;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = getMiddle(tl, tr);
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] * t[v * 2 + 1];
    }
}

Matrix2x2 get(int v, int tl, int tr, int l, int r) {
    if (tr < l || tl > r) return Matrix2x2(1, 0, 0, 1);
    if (tr <= r && tl >= l) return t[v];
    int tm = getMiddle(tl, tr);
    Matrix2x2 a = get(2 * v, tl, tm, l, r);
    Matrix2x2 b = get(2 * v + 1, tm + 1, tr, l, r);
    return a * b;
}

int main() {
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);

    scanf("%d %d %d", &r, &n, &m);
    a.resize((unsigned) n);
    t.resize((unsigned) 4 * n);

    for (int i = 0; i < n; i++) {
        long long a11, a12, a21, a22;
        scanf("%lld %lld %lld %lld", &a11, &a12, &a21, &a22);
        a[i] = Matrix2x2(a11, a12, a21, a22);

    }

    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Matrix2x2 res = get(1, 0, n - 1, l - 1, r - 1);
        printf("%lld %lld\n%lld %lld\n", res.a11, res.a12, res.a21, res.a22);
    }

    return 0;
}