#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string inp;
    cin >> inp;

    // 문자를 저장하는 스택
    stack<char> stk;
    int tmp = 1;
    int ans = 0;
    
    // 해결의 핵심: 분배법칙 (()[[]]) => 2 * (2+3*3) = 2*2 + 2*3*3
    // 여는 괄호의 경우 *연산, 닫는 괄호의 경우 
    // 바로 직전의 문자가 알맞는 여는 괄호라면 점수 추가 후 /연산
    for (int i=0; i<inp.length(); i++) {
        if (inp[i] == '(') {
            tmp *= 2;
            stk.push(inp[i]);
        } else if (inp[i] == '[') {
            tmp *= 3;
            stk.push(inp[i]);
        } else if (inp[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                ans = 0;
                break;
            }
            if (inp[i-1] == '(') {
                ans += tmp;
            }
            stk.pop();
            tmp /= 2;
        } else if (inp[i] == ']') {
            if (stk.empty() || stk.top() != '[') {
                ans = 0;
                break;
            }
            if (inp[i-1] == '[') {
                ans += tmp;
            }
            stk.pop();
            tmp /= 3;
        }
    }

    // 전부 완료했을 때 스택이 차있으면 잘못된 문자열
    if (stk.empty())
        cout << ans << "\n";
    else
        cout << 0;
}

