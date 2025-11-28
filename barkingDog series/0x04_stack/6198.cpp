#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // 80000 * 79999 / 2 > INT_MAX
    long long ans = 0;

    stack<int> stk;
    
    while (n--) {
        int h;
        cin >> h;
        // 기존 주석
        // 핵심 로직: 입력 빌딩보다 낮은 애들을 스택에서 빼야함 
        // -> 이미 스택에 있는 빌딩은 들어오면서 볼 수 있는 애들은 봤음
        // 즉 얘를 못보는 애들은 제거해준 후 높은 빌딩만큼 정답에 더하기

        // 💡 수정 제안 (관점의 명확화)
        // 핵심 로직: "나(h)를 볼 수 없는 빌딩은 스택에서 제거한다."
        // 1. 스택에 있는 빌딩이 나보다 낮거나 같다면(<= h), 그 빌딩은 나 때문에 시야가 막혀서 
        //    더 이상 오른쪽(미래)을 볼 수 없다. -> 제거(pop)
        // 2. 제거 작업 후 스택에 남은 빌딩들은 모두 나보다 높다.
        //    즉, 남은 빌딩들은 모두 "나를 볼 수 있는 관리인들"이다. -> ans += stk.size()
        while (!stk.empty() && stk.top() <= h) {
            stk.pop();
        }
        ans += stk.size();
        stk.push(h);
    }
    cout << ans;
    return 0;
}