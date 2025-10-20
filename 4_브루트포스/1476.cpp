#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int E, S, M;
    cin >> E >> S >> M;
    int e = 1, s = 1, m = 1, year = 1;
    while (true) {
        if (e == E && s == S && m == M) {
            cout << year << "\n";
            break;
        }
        e = e % 15 + 1;
        s = s % 28 + 1;
        m = m % 19 + 1;
        ++year;
    }
    return 0;
}
