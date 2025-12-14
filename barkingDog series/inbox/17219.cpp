#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;

    map<string, string> pws;
    while (n--) {
        string id, pw;
        cin >> id >> pw;

        pws.insert({ id, pw });
    }

    while (m--) {
        string tmp;
        cin >> tmp;

        cout << pws.find(tmp)->second << "\n";
    }
    return 0;
}