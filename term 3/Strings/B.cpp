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


int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> res = prefixFunction(s);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}