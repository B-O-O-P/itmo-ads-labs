#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

const size_t alphabet = 256;

string kthShift(const string& s, int k) {
    size_t n = s.size();
    vector<int> classes(n), pm(n), count(max(n, alphabet));

    for (int i = 0; i < n; ++i) {
        count[s[i]]++;
    }

    for (int i = 1; i < alphabet; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        pm[--count[s[i]]] = i;
    }

    classes[pm[0]] = 0;
    int numberCl = 1;
    for (int i = 1; i < n; i++) {
        if (s[pm[i]] != s[pm[i - 1]]) {
            numberCl++;
        }
        classes[pm[i]] = numberCl - 1;
    }

    vector<int> npm(n), nclasses(n);
    for (int j = 0; (1 << j) < n; ++j) {
        int len = 1 << j;

        for (int i = 0; i < n; ++i) {
            npm[i] = pm[i] - len;
            if (npm[i] < 0) {
                npm[i] += n;
            }
        }

        fill(count.begin(), count.begin() + numberCl, 0);
        for (int i = 0; i < n; ++i) {
            count[classes[npm[i]]]++;
        }

        for (int i = 1; i < numberCl; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            pm[--count[classes[npm[i]]]] = npm[i];
        }

        nclasses[pm[0]] = 0;
        numberCl = 1;
        for (int i = 1; i < n; ++i) {
            pair<int, int> current = {classes[pm[i]], classes[(pm[i] + (1 << j)) % n]};
            pair<int, int> prev = {classes[pm[i - 1]], classes[(pm[i - 1] + (1 << j)) % n]};
            if (current != prev) {
                numberCl++;
            }
            nclasses[pm[i]] = numberCl - 1;
        }
        classes.swap(nclasses);
    }

    vector<int> used(n, false);

    int cur = -1;
    if (k >= n) {
        return "IMPOSSIBLE";
    }

    for (int i = 0; i < n; ++i) {
        if (!used[classes[pm[i]]]) {
            used[classes[pm[i]]] = true;
            cur++;
        }

        if (cur == k) {
            string res = s.substr(pm[i], n - (pm[i])) + s.substr(0, pm[i]);
            return res;
        }
    }

    return "IMPOSSIBLE";
}


int main() {
    freopen("shifts.in", "r", stdin);
    freopen("shifts.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    string s;
    int k;

    cin >> s >> k;
    k--;

    cout << kthShift(s, k);

    return 0;
}