#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string inp;
        getline(cin, inp);

        if (inp == ".") {
            break;
        }

        stack<char> stk;
        bool flag = true;
        
        for (auto t : inp) {
            if (t == '[' || t == '(') {
                stk.push(t);
            } else if (t == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if (t == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    flag = false;
                    break;
                }
            } else {
                continue;
            }
        }
        
        if (flag || stk.empty()) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
    
    return 0;
}