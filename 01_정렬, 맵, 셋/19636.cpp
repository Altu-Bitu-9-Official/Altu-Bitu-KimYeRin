#include <bits/stdc++.h>
using namespace std;


// 체중과 결과 반환(기초대사량 변화 반영 X)
bool simulateWithoutBmrChange(int w0, int i0, int d, int i, int a, int& w_out) {
    w_out = w0 + d * (i - (i0 + a));
    return (w_out <= 0);  // 체중이 0 이하면 사망
}

// 체중, 기초대사량, 결과 반환(기초대사량 변화 반영 O)
bool simulateWithBmrChange(int w0, int b0, int t, int d, int i, int a,
    int& w_out, int& b_out) {
    w_out = w0;
    b_out = b0;

    for (int day = 0; day < d; ++day) {
        int diff = i - (b_out + a); 
        w_out += diff;              // 체중 변화

        // 사망 조건 체크
        if (w_out <= 0) return true;

        // 기초대사량 변화
        if (abs(diff) > t) {
            // 음수일 때 버림이 필요하므로 실수로 나누기
            b_out += static_cast<int>(floor(diff / 2.0));
        }

        if (b_out <= 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w0, i0, t;
    int d, i, a;
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    // 1) 기초대사량 변화 X
    int w_no_change = 0;
    bool dead_no_change = simulateWithoutBmrChange(w0, i0, d, i, a, w_no_change);

    if (dead_no_change) {
        cout << "Danger Diet\n";
    }
    else {
        cout << w_no_change << ' ' << i0 << '\n';
    }

    // 2) 기초대사량 변화 O
    int w_change = 0, b_change = 0;
    bool dead_change = simulateWithBmrChange(w0, i0, t, d, i, a, w_change, b_change);

    if (dead_change) {
        cout << "Danger Diet\n";
        return 0;
    }

    // 요요 판정
    cout << w_change << ' ' << b_change << ' '
        << (i0 > b_change ? "YOYO" : "NO");

    return 0;
}
