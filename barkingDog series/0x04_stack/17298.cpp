#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    stack<pair<int, int>> stk;
    vector<int> vec(n, -1);

    // 입력보다 작은 스택 내부 요소 빼면서 vec[idx]위치에 입력 할당(오큰수)
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;

        while (!stk.empty() && stk.top().first < k) {
            vec[stk.top().second] = k;
            stk.pop();
        }
        
        stk.push({k, i});
    }

    for (int i=0; i < n; i++) {
        cout << vec[i] << " ";
    }

    return 0;
}