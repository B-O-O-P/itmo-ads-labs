#include <iostream>

using namespace std;

long long n, m, * a, v;

struct Node {
    long long sum;
    long long hsum;
    long long l;
    long long r;
};

long long* prefhsum;
long long* prefsum;
long long* hf;
Node* t;

long long sum(long long l, long long r, long long current) {
    if (t[current].r < l || r < t[current].l)
        return 0;

    if (t[current].l >= l && r >= t[current].r)
        return t[current].sum;

    return sum(l, r, 2 * current + 1) + sum(l, r, 2 * current + 2);
}

long long hsum(long long l, long long r, long long current) {
    if (t[current].r < l || r < t[current].l)
        return 0;

    if (t[current].l >= l && r >= t[current].r)
        return t[current].hsum;

    return hsum(l, r, 2 * current + 1) + hsum(l, r, 2 * current + 2);
}

void set(long long i, long long value) {
    i = v + i - 2;
    t[i].sum = value;
    t[i].hsum = hf[value];
    long long j = i;

    while (j >= 1) {
        j = (j - 1) / 2;
        t[j].sum = t[2 * j + 1].sum + t[2 * j + 2].sum;
        t[j].hsum = t[2 * j + 1].hsum + t[2 * j + 2].hsum;
    }
}

void upToDegree() {
    while (n > v) {
        v = v << 1;
    }
}

void hashh() {
    hf[0] = 1;

    for (int i = 0; i < n; i++) {
        t[v + i - 1].sum = a[i];
        hf[i + 1] = hf[i] * 7;
    }

    hf[n] = hf[n - 1] * 7;
}

void prefsumms() {
    prefsum[0] = 0;
    prefhsum[0] = 0;

    for (int i = 1; i < n + 1; i++) {
        prefhsum[i] = prefhsum[i - 1] + hf[i];
        prefsum[i] = prefsum[i - 1] + i;
    }

    for (int i = 0; i < n; i++) {
        t[v + i - 1].hsum = hf[a[i]];
    }
}

void build() {
    for (long long i = v - 2; i >= 0; i--) {
        t[i].sum = t[2 * i + 1].sum + t[2 * i + 2].sum;
        t[i].hsum = t[2 * i + 1].hsum + t[2 * i + 2].hsum;
        t[i].l = t[2 * i + 1].l;
        t[i].r = t[2 * i + 2].r;
    }
}

int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);

    scanf("%lld", &n);

    a = new long long[n];
    hf = new long long[n + 1];
    prefsum = new long long[n + 1];
    prefhsum = new long long[n + 1];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    v = 1;
    upToDegree();
    long long size = v << 1;
    t = new Node[size];

    for (int i = 0; i < size; i++) {
        t[i].sum = 0;
        t[i].l = i;
        t[i].r = i;
    }

    hashh();
    prefsumms();
    build();

    scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        long long f, x, y;
        scanf("%lld %lld %lld", &f, &x, &y);

        if (f == 1) set(x, y);
        else {
            long long length = y - x + 1;
            long long hashsumm = hsum(v + x - 2, v + y - 2, 0);
            long long summ = sum(v + x - 2, v + y - 2, 0);

            if (summ == prefsum[length] && hashsumm == prefhsum[length])
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}