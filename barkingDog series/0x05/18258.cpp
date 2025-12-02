#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    queue<int> q;

    while (n--) {
        string inp;
        cin >> inp;
        
        if (inp == "push") {
            int k;
            cin >> k;
            q.push(k);
        } else if (inp == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        } else if (inp == "size") {
            cout << q.size() << "\n";
        } else if (inp == "empty") {
            cout << q.empty() << "\n";
        } else if (inp == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
        } else {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.back() << "\n";
        }
    }
}