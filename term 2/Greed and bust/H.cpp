#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> vectors;

int main() {
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);

    scanf("%d", &n);

    int m = 1 << n;
    for (int i = 0; i < m; i++) {
        string s;
        int pref = 0;
        int cur = i;
        bool hasone = false;
        for (int j = 0; j < n; j++) {
            if (cur % 2 == 1 && pref == 1) {
                hasone = true;
                break;
            }
            s = to_string(cur % 2) + s;
            if (cur % 2 == 1) { pref = 1; }
            else { pref = 0; }
            cur = cur / 2;
        }

        if (!hasone) {
            vectors.push_back(s);
        }
    }

    int count = vectors.size();
    printf("%d\n", count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", vectors[i]);
    }

    return 0;
}