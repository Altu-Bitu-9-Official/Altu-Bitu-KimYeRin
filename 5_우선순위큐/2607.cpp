#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string base;
    cin >> base;

    array<int, 26> baseCnt{};
    for (char c : base) baseCnt[c - 'A']++;

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        string s; cin >> s;
        array<int, 26> cnt{};
        for (char c : s) cnt[c - 'A']++;

        // �켱���� ť�� |baseCnt - cnt| �ְ� �ջ�
        priority_queue<int> diffs; // max-heap (��� �ո� �ʿ��ϹǷ� �������� �䱸 ����)
        for (int k = 0; k < 26; ++k) diffs.push(abs(baseCnt[k] - cnt[k]));

        int diffSum = 0;
        while (!diffs.empty()) { diffSum += diffs.top(); diffs.pop(); }

        int dl = (int)base.size() - (int)s.size();
        int absDl = abs(dl);

        bool similar = false;
        if (absDl == 0) similar = (diffSum == 0 || diffSum == 2);
        else if (absDl == 1) similar = (diffSum == 1);

        if (similar) ++ans;
    }
    cout << ans << "\n";
    return 0;
}
