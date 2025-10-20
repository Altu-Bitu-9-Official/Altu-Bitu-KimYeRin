#include <bits/stdc++.h>
using namespace std;

struct Person {
    int d, h;      // �ٹ��ϼ�, Ű
    int idx;       // ��ü �Է� �ε���(0-based)
};
struct Item {
    int d, h;
    int line;      // �� ��ȣ(0-based)
    int idx;       // ��ü �ε���(0-based)
};
struct Cmp {
    bool operator()(const Item& a, const Item& b) const {
        if (a.d != b.d) return a.d < b.d;      // d ū ���� �켱
        if (a.h != b.h) return a.h < b.h;      // h ū ���� �켱
        return a.line > b.line;                // �� ��ȣ ���� ���� �켱
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
        if (cur.idx == K) {          // K��° ����� ���� ����
            cout << popped << "\n";  // K ������ ���� ��� ��
            return 0;
        }
        // ���� �ٿ��� �� �� ����
        lines[cur.line].pop_front();
        // ���� �ĺ��� ������ �ֱ�
        if (!lines[cur.line].empty()) {
            auto nxt = lines[cur.line].front();
            pq.push({ nxt.d, nxt.h, cur.line, nxt.idx });
        }
        ++popped;
    }
    return 0;
}
