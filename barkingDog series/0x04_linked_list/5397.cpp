#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    while (n--) {
        string inp;
        cin >> inp;

        list<char> lst;
        auto cursor = lst.end();

        for (auto t : inp) {
            if (t == '<') {
                if (cursor != lst.begin()) {
                    cursor--;
                }
            } else if (t == '>') {
                if (cursor != lst.end()) {
                    cursor++;
                }
            } else if (t == '-') {
                if (cursor != lst.begin()) {
                    cursor--;
                    cursor = lst.erase(cursor);
                }
            } else {
                // 일반 문자인 경우
                lst.insert(cursor, t);
            }
        }

        for (auto t : lst) {
            cout << t;
        }
        cout << "\n";
    }
}