#include <bits/stdc++.h>
using namespace std;

// ���ڿ� �� ������ �� ���
int sumDigits(const string& s) {
    int result = 0;
    for (char ch : s) {
        if ('0' <= ch && ch <= '9') {
            result += ch - '0';
        }
    }
    return result;
}

// ���� ���� : 1) ���� 2) ���� �� 3) ������
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
