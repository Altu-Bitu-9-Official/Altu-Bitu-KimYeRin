#include <bits/stdc++.h>
using namespace std;

// 문자열 안 숫자의 합 계산
int sumDigits(const string& s) {
    int result = 0;
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') {
            result += ch - '0';
        }
    }
    return result;
}

// 정렬 기준 : 1) 길이 2) 숫자 합 3) 사전순
bool compareSerial(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }

    int sa = sumDigits(a);
    int sb = sumDigits(b);
    if (sa != sb) {
        return sa < sb;
    }

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> serials;
    serials.reserve(n);

    for (int i = 0; i < n; i++) {
        string serial;
        cin >> serial;
        serials.push_back(serial);
    }

    sort(serials.begin(), serials.end(), compareSerial);

    for (const auto& s : serials) {
        cout << s << '\n';
    }
    return 0;
}
