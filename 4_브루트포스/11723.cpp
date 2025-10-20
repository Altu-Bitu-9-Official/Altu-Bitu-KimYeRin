#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    // 브루트하게 불리언 배열로 관리 (1..20)
    array<bool, 21> has{};
    has.fill(false);

    while (M--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int x; cin >> x; has[x] = true;
        }
        else if (cmd == "remove") {
            int x; cin >> x; has[x] = false;
        }
        else if (cmd == "check") {
            int x; cin >> x; cout << (has[x] ? 1 : 0) << "\n";
        }
        else if (cmd == "toggle") {
            int x; cin >> x; has[x] = !has[x];
        }
        else if (cmd == "all") {
            for (int i = 1; i <= 20; ++i) has[i] = true;
        }
        else if (cmd == "empty") {
            for (int i = 1; i <= 20; ++i) has[i] = false;
        }
    }
    return 0;
}
