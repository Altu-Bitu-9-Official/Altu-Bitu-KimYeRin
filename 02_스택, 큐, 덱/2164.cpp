#include <bits/stdc++.h>
using namespace std;

// 큐로 카드 버리기/뒤로 옮기기 시뮬레이션
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);

    while (q.size() > 1) {
        q.pop();                 // 맨 위 버림
        q.push(q.front());       // 다음 카드를 뒤로
        q.pop();
    }
    cout << q.front();
    return 0;
}
