#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> pq; // min-heap
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            long long x; cin >> x;
            pq.push(x);
            if ((int)pq.size() > N) pq.pop();
        }
    }
    cout << pq.top() << "\n";
    return 0;
}
