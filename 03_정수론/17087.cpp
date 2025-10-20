#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    if (!(cin >> N >> S)) return 0;

    long long g = 0;
    for (int i = 0; i < N; ++i) {
        long long x; cin >> x;
        long long d = llabs(x - S);
        g = std::gcd(g, d);
    }
    cout << g << "\n";
    return 0;
}
