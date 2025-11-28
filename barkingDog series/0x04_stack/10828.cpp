#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    stack<int> stk;

    while (n--) {
        string inp;
        cin >> inp;
        if (inp == "push") {
            int el;
            cin >> el;

            stk.push(el);
        } else if (inp == "top") {
            if (stk.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << stk.top() << "\n";
        } else if (inp == "pop") {
            if (stk.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << stk.top() << "\n";
            stk.pop();
        } else if (inp == "size") {
            cout << stk.size() << "\n";
        } else {
            cout << stk.empty() << "\n";
        }
    }
}