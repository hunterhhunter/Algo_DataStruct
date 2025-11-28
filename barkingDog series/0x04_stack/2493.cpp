#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, idx = 0; 
    cin >> n;

    stack<pair<int, int>> stk;
    string ans = "";

    for (int i=1; i<n+1; i++) {
        int h;
        cin >> h;

        // 나보다 큰 애를 만났을 때 정답 추가하고 멈추는게 중요
        while (!stk.empty()) {
            if (stk.top().second > h) {
                ans += to_string(stk.top().first) + " ";
                break;
            }
            stk.pop();
        }

        if (stk.empty()) {
            ans += "0 ";
        }
        stk.push(make_pair(i, h));
    }

    cout << ans;

    return 0;
}