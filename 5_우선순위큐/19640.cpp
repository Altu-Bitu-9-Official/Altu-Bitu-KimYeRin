#include <bits/stdc++.h>
using namespace std;

struct Person {
    int d, h;      // 근무일수, 키
    int idx;       // 전체 입력 인덱스(0-based)
};
struct Item {
    int d, h;
    int line;      // 줄 번호(0-based)
    int idx;       // 전체 인덱스(0-based)
};
struct Cmp {
    bool operator()(const Item& a, const Item& b) const {
        if (a.d != b.d) return a.d < b.d;      // d 큰 것이 우선
        if (a.h != b.h) return a.h < b.h;      // h 큰 것이 우선
        return a.line > b.line;                // 줄 번호 작은 것이 우선
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<deque<Person>> lines(M);
    lines.assign(M, {});
    for (int i = 0; i < N; ++i) {
        int d, h; cin >> d >> h;
        lines[i % M].push_back({ d, h, i });
    }

    priority_queue<Item, vector<Item>, Cmp> pq;
    for (int line = 0; line < M; ++line) {
        if (!lines[line].empty()) {
            auto p = lines[line].front();
            pq.push({ p.d, p.h, line, p.idx });
        }
    }

    long long popped = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.idx == K) {          // K번째 사람이 나갈 차례
            cout << popped << "\n";  // K 이전에 나간 사람 수
            return 0;
        }
        // 현재 줄에서 한 명 제거
        lines[cur.line].pop_front();
        // 다음 후보가 있으면 넣기
        if (!lines[cur.line].empty()) {
            auto nxt = lines[cur.line].front();
            pq.push({ nxt.d, nxt.h, cur.line, nxt.idx });
        }
        ++popped;
    }
    return 0;
}
