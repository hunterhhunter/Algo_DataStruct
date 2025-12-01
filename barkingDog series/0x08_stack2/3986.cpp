#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    while (n--) {
        string inp;
        cin >> inp;

        stack<char> stk;
        
        // 핵심은  AA / BB 처럼 연속될 때 pop
        // 남은 애들은 짝지어지지 않은 애들
        for (int i=0; i<inp.length(); i++) {
            if (inp[i] == 'A') {
                if (!stk.empty() && stk.top() == 'A') {
                    stk.pop();
                    continue;
                }
            } else {
                if (!stk.empty() && stk.top() == 'B') {
                    stk.pop();
                    continue;
                }
            }
            stk.push(inp[i]);
        }

        if (stk.empty()) {
            ans++;
        }
    }
    cout << ans;
    
    return 0;
}