#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans=0;
    cin >> n;

    stack<int> stk;

    while (n--) {
        int k;
        cin >> k;
        
        if (k == 0) {
            ans -= stk.top();
            stk.pop();
        } else {
            ans += k;
            stk.push(k);
        }
    }

    cout << ans << "\n";
    return 0;
}