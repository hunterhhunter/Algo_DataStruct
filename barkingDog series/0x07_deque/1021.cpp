#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dq;

    while (n--) {
        dq.push_front(n+1);
    }

    int ans = 0;

    while (m--) {
        int front = 0;
        int back = 0;

        int tmp, idx = 0;
        cin >> tmp;

        while (idx < dq.size()) {
            if (dq[idx] == tmp) {
                front = idx; // idx 번만큼 왼쪽회전시 원하는 수가 1번원소
                back = dq.size() - idx; // size - idx번 우측회전시 원하는 수가 1번 원소
                break;
            }
            idx++;
        }

        if (front > back) {
            ans += back;
            while (back--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            ans += front;
            while (front--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        dq.pop_front();
    }

    cout << ans << "\n";

    return 0;
}