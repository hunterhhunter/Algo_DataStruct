#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    stack<char> stk;
    int ans = 0;

    for (int i=0; i<inp.length(); i++) {
        // 레이저의 경우
        if (i+1 < inp.length() && inp[i] == '(' && inp[i+1] == ')') {
            ans += stk.size();
            i++;
        } else if (inp[i] == '(') {
            stk.push(inp[i]);
        } else if (inp[i] == ')') {
            stk.pop();
            // 쇠막대 닫히는 순간에 1개 추가
            ans += 1;
        }
    }

    cout << ans << "\n";

    return 0;
}