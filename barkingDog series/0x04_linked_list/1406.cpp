#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string inp;
    cin >> inp;

    int n;
    cin >> n;

    list<char> lst;
    for (auto t : inp) lst.push_back(t);
    auto cursor = lst.end();

    char command, param;
    for (int i=0; i<n; i++) {
        cin >> command;
        if (command == 'P') {
            // 삽입
            cin >> param;
            lst.insert(cursor, param);
        } else if (command == 'L') {
            if (cursor != lst.begin()) {
                cursor--;
            }
        } else if (command == 'D') {
            if (cursor != lst.end()) {
                cursor++;
            }
        } else if (command == 'B') {
            if (cursor != lst.begin()) {
                cursor--;
                cursor = lst.erase(cursor);
            }
        }
    }
    for (auto t : lst) {
        cout << t;
    }
}