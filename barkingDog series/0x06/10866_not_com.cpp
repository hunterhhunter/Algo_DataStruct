#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;
    int n;
    cin >> n;

    while (n--) {
        string inp;
        cin >> inp;

        if (inp == "push_front") {
            int tmp; cin >> tmp;
            dq.push_front(tmp);
        } else if (inp == "push_back") {
            int tmp; cin >> tmp;
            dq.push_back(tmp);
        } else if (inp == "pop_front") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        } else if (inp == "pop_back") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        } else if (inp == "size") {
            cout << dq.size() << "\n";
        } else if (inp == "empty") {
            cout << dq.empty() << "\n";
        } else if (inp == "front") {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.front() << "\n";
        } else {
            if (dq.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << dq.back() << "\n";
        }
    }
    return 0;
}