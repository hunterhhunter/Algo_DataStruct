#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    list<int> lst;

    for (int i=1; i<n+1; i++) {
        lst.push_back(i);
    }

    auto cursor = lst.begin();

    cout << "<";
    while (!lst.empty()) {
        for (int i=0; i<k-1; i++) {
            cursor++;
            if (cursor == lst.end()) {
                cursor = lst.begin();
            }
        }
        if (lst.size() == 1) cout << *cursor;
        else cout << *cursor << ", ";

        cursor = lst.erase(cursor);
        if (cursor == lst.end()) {
            cursor = lst.begin();
        }
    }

    cout << ">";
}