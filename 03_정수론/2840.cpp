#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<char> wheel(n, '?');
    // 알파벳 위치 기록: 미배치 -1, 배치되면 해당 인덱스
    vector<int> where(26, -1);

    int pos = 0; // 바늘 위치(0-based)
    for (int i = 0; i < m; ++i) {
        int s; char c;
        cin >> s >> c;
        pos = (pos + s) % n;                  // 모듈러로 바늘 위치 갱신 (정수론)
        int ci = c - 'A';

        // 1) 이미 그 칸에 다른 글자가 있으면 모순
        if (wheel[pos] != '?' && wheel[pos] != c) {
            cout << "!\n";
            return 0;
        }
        // 2) 같은 글자가 다른 칸에 이미 있으면 모순
        if (where[ci] != -1 && where[ci] != pos) {
            cout << "!\n";
            return 0;
        }
        // 3) 배치
        wheel[pos] = c;
        where[ci] = pos;
    }

    // 최종 출력: 현재 바늘(pos)에서 시작해 시계 반대방향(인덱스 감소)으로 n글자
    string ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
        int idx = (pos - i) % n;
        if (idx < 0) idx += n;                // C++의 음수 mod 보정
        ans.push_back(wheel[idx]);
    }

    cout << ans << "\n";
    return 0;
}
