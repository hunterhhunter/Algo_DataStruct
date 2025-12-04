#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

struct value {
    int val;
    int idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;

    deque<value> dq;

    // 항상 가장 앞의 원소가 가장 작은 원소.
    // 모노톤큐로 해결
    // 1. 입력보다 큰 애들은 pop_back
    // 2. 입력 push_back
    // 3. 앞쪽에 인덱스 다 지난 애들 push_front
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;

        while (!dq.empty() && tmp < dq.back().val) {
            dq.pop_back();
        }

        dq.push_back({ tmp, i });

        // 인덱스 초과인 애들 pop
        while (!dq.empty() && dq.front().idx < (i-l+1)) {
            dq.pop_front();
        }

        cout << dq.front().val << " ";
    }

    return 0;
}