#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string tmp; cin >> tmp;
    vector<string> ans;
    
    for (int i=0; i<tmp.length(); i++) {
        ans.push_back(tmp.substr(i, tmp.length()));
    }    sort(ans.begin(), ans.end());

    for (auto t : ans) {
        cout << t << "\n";
    }
    return 0;
}