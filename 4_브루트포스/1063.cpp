#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string king, stone; int N;
    cin >> king >> stone >> N;

    auto pos = [](const string& s) { // "A1" -> (x,y) 0-based
        int x = s[0] - 'A';
        int y = s[1] - '1';
        return pair<int, int>(x, y);
        };
    auto toStr = [](int x, int y) {
        string s;
        s += char('A' + x);
        s += char('1' + y);
        return s;
        };

    auto [kx, ky] = pos(king);
    auto [sx, sy] = pos(stone);

    unordered_map<string, pair<int, int>> d = {
        {"R",{1,0}}, {"L",{-1,0}}, {"B",{0,-1}}, {"T",{0,1}},
        {"RT",{1,1}}, {"LT",{-1,1}}, {"RB",{1,-1}}, {"LB",{-1,-1}}
    };

    auto in = [](int x, int y) { return 0 <= x && x < 8 && 0 <= y && y < 8; };

    while (N--) {
        string cmd; cin >> cmd;
        auto [dx, dy] = d[cmd];
        int nkx = kx + dx, nky = ky + dy;
        if (!in(nkx, nky)) continue;               // 왕이 나가면 명령 무시
        if (nkx == sx && nky == sy) {             // 돌을 밀어야 함
            int nsx = sx + dx, nsy = sy + dy;
            if (!in(nsx, nsy)) continue;          // 돌이 나가면 명령 무시
            // 둘 다 이동
            kx = nkx; ky = nky;
            sx = nsx; sy = nsy;
        }
        else {
            kx = nkx; ky = nky;
        }
    }

    cout << toStr(kx, ky) << "\n" << toStr(sx, sy) << "\n";
    return 0;
}
