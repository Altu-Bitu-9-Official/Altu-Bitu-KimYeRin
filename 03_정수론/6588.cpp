#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1'000'000;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * 1LL * i <= MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) isPrime[j] = false;
        }
    }

    int n;
    while (cin >> n && n != 0) {
        bool found = false;
        for (int a = 3; a <= n - 3; a += 2) {     // a, b�� Ȧ�� �Ҽ�
            if (isPrime[a] && isPrime[n - a]) {
                cout << n << " = " << a << " + " << (n - a) << "\n";
                found = true;
                break; // ù �ظ� ���(�Ϲ������� a�� �ּҰ� ��)
            }
        }
        if (!found) cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
