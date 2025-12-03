#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

struct sqr { int idx, h; };

int main() {
    while (true) {
        int n;
        cin >> n;

        long long ans = 0;

        if (n == 0) {
            break;
        }
        
        stack<sqr> stk;

        for (int i=0; i<=n; i++) {
            int tmp = 0, idx = i;
            if (i != n) cin >> tmp;

            while (!stk.empty() && stk.top().h > tmp) {
                idx = stk.top().idx;
                ans = max(ans, (long long) stk.top().h * (i - idx));
                stk.pop();
            }

            if (stk.empty() || stk.top().h != tmp) {
                stk.push({idx, tmp});
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}