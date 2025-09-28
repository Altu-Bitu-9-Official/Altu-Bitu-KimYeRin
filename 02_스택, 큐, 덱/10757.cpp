#include <bits/stdc++.h>
using namespace std;

// 두 큰 수(문자열)의 합을 덱으로 앞쪽에 쌓아 출력
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    deque<char> dq; // 앞에 넣기

    while (i >= 0 || j >= 0 || carry) {
        int da = (i >= 0 ? a[i] - '0' : 0);
        int db = (j >= 0 ? b[j] - '0' : 0);
        int sum = da + db + carry;

        dq.push_front(char('0' + (sum % 10)));
        carry = sum / 10;

        --i; --j;
    }

    for (char c : dq) cout << c;
    return 0;
}
