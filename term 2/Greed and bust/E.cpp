#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;

struct Apple {
    int a;
    int b;
    int number;
};

vector<Apple> plusa;
vector<Apple> minusb;

bool pluscompare(Apple& a, Apple& b) {
    return (a.a < b.a);
}

bool minuscompare(Apple& a, Apple& b) {
    return (a.b > b.b);
}

int main() {
    freopen("apples.in", "r", stdin);
    freopen("apples.out", "w", stdout);

    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        Apple x;
        x.a = a;
        x.b = b;
        x.number = i;
        if (b - a > 0)
            plusa.push_back(x);
        else
            minusb.push_back(x);
    }

    sort(plusa.begin(), plusa.end(), pluscompare);
    sort(minusb.begin(), minusb.end(), minuscompare);

    vector<int> ressequence;
    for (int i = 0; i < plusa.size(); i++) {
        if (s - plusa[i].a <= 0) {
            printf("-1");
            return 0;
        } else {
            s += (plusa[i].b - plusa[i].a);
            ressequence.push_back(plusa[i].number);
        }
    }

    for (int i = 0; i < minusb.size(); i++) {
        if (s - minusb[i].a <= 0) {
            printf("-1");
            return 0;
        } else {
            s += (minusb[i].b - minusb[i].a);
            ressequence.push_back(minusb[i].number);
        }
    }

    for (int i = 0; i < ressequence.size(); i++) {
        printf("%d ", ressequence[i]);
    }

    return 0;
}