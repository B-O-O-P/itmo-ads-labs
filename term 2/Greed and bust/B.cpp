#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> time;

bool comp(pair<int, int>& x, pair<int, int>& y) {
    return (x.second < y.second);
}

int main() {
    freopen("request.in", "r", stdin);
    freopen("request.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int s, f;
        scanf("%d %d", &s, &f);
        time.emplace_back(make_pair(s, f));
    }

    sort(time.begin(), time.end(), comp);

    int count = 1;
    int curtime = time[0].second;
    int cur = 0;
    while (cur < n) {
        if (time[cur].first < curtime) {
            cur++;
        } else {
            count++;
            curtime = time[cur].second;
        }
    }

    printf("%d", count);

    return 0;
}