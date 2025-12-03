#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    stack<int> stk;
    string ans = "";

    int n, idx = 1;
    cin >> n;

    
    while (n--) {
        int k;
        cin >> k;

        // 핵심은 k까지 입력
        while (k >= idx) {
            stk.push(idx++);
            ans += "+\n";
        }
        
        // 이때 k=top일 때 출력 -> k < idx인 입력에서 top != k이면 만들 수 없는 수열
        if (stk.top() == k) {
            stk.pop();
            ans += "-\n";
        } else {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << ans;

    return 0;
}