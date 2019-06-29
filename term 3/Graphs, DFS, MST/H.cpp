#include <iostream>
#include <vector>
#include <map>
#include <stack>


using namespace std;

int n, m;
vector<vector<int>> graph, invgraph;
vector<bool> used;
stack<int> order;
vector<int> comp;
vector<string> names;
map<string, int> numbers;

int converterWithountNot(int i) {
    return 2 * i;
}

int converterWithNot(int i) {
    return 2 * i + 1;
}

void dfsOne(int v) {
    used[v] = true;

    for (int i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (!used[to]) {
            dfsOne(to);
        }
    }
    order.push(v);
}

void dfsTwo(int v, int col) {
    comp[v] = col;

    for (int i = 0; i < invgraph[v].size(); ++i) {
        int to = invgraph[v][i];
        if (comp[to] == -1)
            dfsTwo(to, col);
    }
}

int main() {
    cin >> n >> m;

    graph.resize(2 * n);
    invgraph.resize(2 * n);
    comp.resize(2 * n);
    used.resize(2 * n);

    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;

        names.push_back(name);
        numbers[name] = i;
    }


    for (int i = 0; i < m; ++i) {
        string firstName, arrow, secondName;
        cin >> firstName >> arrow >> secondName;

        int firstNumber, secondNumber;

        if (firstName[0] == '-') {
            firstNumber = converterWithNot(numbers[firstName.substr(1, firstName.size())]);
        } else firstNumber = converterWithountNot(numbers[firstName.substr(1, firstName.size())]);

        if (secondName[0] == '-') {
            secondNumber = converterWithNot(numbers[secondName.substr(1, secondName.size())]);
        } else secondNumber = converterWithountNot(numbers[secondName.substr(1, secondName.size())]);

        //x => y && !y => !x
        graph[firstNumber].push_back(secondNumber);
        graph[secondNumber ^ 1].push_back(firstNumber ^ 1);
        //y => x && !x => !y
        invgraph[secondNumber].push_back(firstNumber);
        invgraph[firstNumber ^ 1].push_back(secondNumber ^ 1);
    }

    used.assign(2 * n, false);

    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i])
            dfsOne(i);
    }

    comp.assign(2 * n, -1);

    int col = 0;
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (comp[v] == -1) {
            dfsTwo(v, col++);
        }
    }

    for (int i = 0; i < 2 * n; i += 2) {
        if (comp[i] == comp[i ^ 1]) {
            cout << -1;
            return 0;
        }
    }

    vector<string> ans;
    for (int i = 0; i < 2 * n; i += 2) {
        if (comp[i] > comp[i ^ 1]) {
            ans.push_back(names[i / 2]);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}