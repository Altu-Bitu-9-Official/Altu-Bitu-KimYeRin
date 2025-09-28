#include <bits/stdc++.h>
using namespace std;


// ü�߰� ��� ��ȯ(���ʴ�緮 ��ȭ �ݿ� X)
bool simulateWithoutBmrChange(int w0, int i0, int d, int i, int a, int& w_out) {
    w_out = w0 + d * (i - (i0 + a));
    return (w_out <= 0);  // ü���� 0 ���ϸ� ���
}

// ü��, ���ʴ�緮, ��� ��ȯ(���ʴ�緮 ��ȭ �ݿ� O)
bool simulateWithBmrChange(int w0, int b0, int t, int d, int i, int a,
    int& w_out, int& b_out) {
    w_out = w0;
    b_out = b0;

    for (int day = 0; day < d; ++day) {
        int diff = i - (b_out + a); 
        w_out += diff;              // ü�� ��ȭ

        // ��� ���� üũ
        if (w_out <= 0) return true;

        // ���ʴ�緮 ��ȭ
        if (abs(diff) > t) {
            // ������ �� ������ �ʿ��ϹǷ� �Ǽ��� ������
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

    // 1) ���ʴ�緮 ��ȭ X
    int w_no_change = 0;
    bool dead_no_change = simulateWithoutBmrChange(w0, i0, d, i, a, w_no_change);

    if (dead_no_change) {
        cout << "Danger Diet\n";
    }
    else {
        cout << w_no_change << ' ' << i0 << '\n';
    }

    // 2) ���ʴ�緮 ��ȭ O
    int w_change = 0, b_change = 0;
    bool dead_change = simulateWithBmrChange(w0, i0, t, d, i, a, w_change, b_change);

    if (dead_change) {
        cout << "Danger Diet\n";
        return 0;
    }

    // ��� ����
    cout << w_change << ' ' << b_change << ' '
        << (i0 > b_change ? "YOYO" : "NO");

    return 0;
}
