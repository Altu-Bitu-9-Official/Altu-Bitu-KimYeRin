#include <bits/stdc++.h>
using namespace std;

// 한 줄이 균형 잡혔는지 검사
bool isBalanced(const string& line) {
    stack<char> st;
    for (char ch : line) {
        if (ch == '(' || ch == '[') st.push(ch);
        else if (ch == ')' || ch == ']') {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (ch == ')' && top != '(') return false;
            if (ch == ']' && top != '[') return false;
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        getline(cin, line);
        if (!cin) break;       
        if (line == ".") break;  // 종료 조건

        cout << (isBalanced(line) ? "yes" : "no") << '\n';
    }
    return 0;
}
