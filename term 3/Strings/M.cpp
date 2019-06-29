#include <iostream>
#include <vector>


using namespace std;

const size_t alphabet = 256;

struct SuffixArray {
    explicit SuffixArray(const string& str) : s(str), permutation(str.size()) {
        s.push_back(1);
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

        for (int i = 0; i < n - 1; ++i) {
            permutation[i] = pm[i + 1];
        }
        s.pop_back();
    }

    vector<int> kasaiLCP() {
        size_t n = permutation.size();

        vector<int> r(n), res(n - 1);
        for (int i = 0; i < n; ++i) {
            r[permutation[i]] = i;
        }

        s.push_back(1);

        int current = 0;
        for (int i = 0; i < n; ++i) {
            if (current > 0) {
                --current;
            }
            if (r[i] == n - 1) {
                current = 0;
            } else {
                while (s[i + current] == s[permutation[r[i] + 1] + current]) {
                    current++;
                }
                res[r[i]] = current;
            }
        }
        s.pop_back();

        return res;
    }

    long long numberOfDifferentSubs() {
        size_t n = permutation.size();

        vector<int> r(n), res(n - 1);
        for (int i = 0; i < n; ++i) {
            r[permutation[i]] = i;
        }

        s.push_back(1);

        int current = 0;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (current > 0) {
                --current;
            }
            if (r[i] == n - 1) {
                current = 0;
            } else {
                while (s[i + current] == s[permutation[r[i] + 1] + current]) {
                    current++;
                }
                res[r[i]] = current;
                sum += current;
            }
        }
        s.pop_back();

        long long ans = (long long) n * (long long) (n + 1) / 2 - sum;
        return ans;
    }

    void print() {
        for (int i : permutation) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }


    string s;
    vector<int> permutation;
};

string LCS(string& s, string& t, int len) {
    string T = s + "#" + t;
    SuffixArray suffixArray(T);

    vector<int> lcp = suffixArray.kasaiLCP();
    size_t n = lcp.size();
    int max = -1;
    int maxNumber = 0;

    for (int i = 0; i < n; ++i) {
        if ((suffixArray.permutation[i]) < len && suffixArray.permutation[i + 1] >= len ||
            (suffixArray.permutation[i] >= len &&
             suffixArray.permutation[i + 1] < len)) {
            if (lcp[i] > max) {
                max = lcp[i];
                maxNumber = suffixArray.permutation[i];
            }
        }
    }

    return suffixArray.s.substr(maxNumber, max);
}

int main() {
    freopen("common.in", "r", stdin);
    freopen("common.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    int minLen = min(s.size(), t.size());

    cout << LCS(s, t, minLen);

    return 0;
}