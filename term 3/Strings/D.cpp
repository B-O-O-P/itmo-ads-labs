#include <iostream>
#include <vector>


using namespace std;

vector<int> prefixFunction(const string& s) {
    size_t n = s.length();
    vector<int> prefix(n);
    prefix[0] = 0;

    for (int i = 1; i < n; ++i) {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        };
        prefix[i] = j;
    }

    return prefix;
}

vector<int> KMP(const string& pattern, const string& text) {
    int pSize = pattern.length();
    int tSize = text.length();
    vector<int> prefix = prefixFunction(pattern + "#" + text);
    vector<int> res;

    for (int i = pSize; i < pSize + 1 + tSize; ++i) {
        if (prefix[i] == pSize) {
            res.push_back(i - pSize * 2 + 1);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    string p, t;
    cin >> p >> t;

    vector<int> res = KMP(p, t);

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}