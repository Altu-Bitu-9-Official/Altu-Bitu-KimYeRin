#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<char> wheel(n, '?');
    // ���ĺ� ��ġ ���: �̹�ġ -1, ��ġ�Ǹ� �ش� �ε���
    vector<int> where(26, -1);

    int pos = 0; // �ٴ� ��ġ(0-based)
    for (int i = 0; i < m; ++i) {
        int s; char c;
        cin >> s >> c;
        pos = (pos + s) % n;                  // ��ⷯ�� �ٴ� ��ġ ���� (������)
        int ci = c - 'A';

        // 1) �̹� �� ĭ�� �ٸ� ���ڰ� ������ ���
        if (wheel[pos] != '?' && wheel[pos] != c) {
            cout << "!\n";
            return 0;
        }
        // 2) ���� ���ڰ� �ٸ� ĭ�� �̹� ������ ���
        if (where[ci] != -1 && where[ci] != pos) {
            cout << "!\n";
            return 0;
        }
        // 3) ��ġ
        wheel[pos] = c;
        where[ci] = pos;
    }

    // ���� ���: ���� �ٴ�(pos)���� ������ �ð� �ݴ����(�ε��� ����)���� n����
    string ans;
    ans.reserve(n);
    for (int i = 0; i < n; ++i) {
        int idx = (pos - i) % n;
        if (idx < 0) idx += n;                // C++�� ���� mod ����
        ans.push_back(wheel[idx]);
    }

    cout << ans << "\n";
    return 0;
}
