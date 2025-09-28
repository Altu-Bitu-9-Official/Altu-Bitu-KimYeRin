#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    set<string> new_set;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        string cur;
        cur.reserve(n - i);
        for (int j = i; j < n; ++j) {
            cur.push_back(s[j]);
            new_set.insert(cur);
        }
    }

    cout << new_set.size();
    return 0;
}