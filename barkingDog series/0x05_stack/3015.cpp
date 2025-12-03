#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    stack<pair<long long, long long>> stk;

    unsigned long long ans = 0;

    // 해결 전략
    // 1. 스택에 top보다 크거나 같은 값이 들어갈 때 만들 수 있는 조합의 수를 구하기
    // 이 때 전의 같은 애들은 서로 볼 수 있음 + pop
    // 이 과정 후 스택이 차있으면 자기자신과 현재 top과 만들 수 있는 조합 +1개
    while (n--) {
        long long tmp;
        cin >> tmp;

        // 크기 같은 애들 압축
        int same_height_cnt = 1;

        // 스택 안 비어있고 입력 >= top()
        while (!stk.empty() && stk.top().first <= tmp) {
            ans += stk.top().second; // 전의 같은 애들에 대해 만들 수 있는 조합 개수 최소 1
            if (stk.top().first == tmp) {
                // 입력의 크기가 같으면 전의 값+1로 초기화
                same_height_cnt += stk.top().second;
            }
            stk.pop();
        }

        if (!stk.empty()) {
            ans += 1; // 스택의 큰 애에 대해 만들 수 있는 조합
        }

        stk.push({tmp, same_height_cnt});

    }

    cout << ans;
    
    return 0;
}