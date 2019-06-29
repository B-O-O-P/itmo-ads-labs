#include <iostream>
#include <vector>


using namespace std;

vector<int> zFunction(const string& s) {
    size_t n = s.length();
    vector<int> z(n);
    z[0] = 0;

    int left = 0;
    int right = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    vector<int> res = zFunction(s);

    for (int i = 1; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}