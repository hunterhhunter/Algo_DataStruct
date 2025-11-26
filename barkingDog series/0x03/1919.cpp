#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0;
    // a = 97

    vector<vector<int>> arr(2, vector<int>(26, 0));
    
    string a, b;
    cin >> a;
    cin >> b;

    for (int j=0; j<a.length(); j++) {
        arr[0][(int)a[j]-97]++;
    }

    for (int j=0; j<b.length(); j++) {
        arr[1][(int)b[j]-97]++;
    }

    for (int k=0; k<26; k++) {
        if (arr[0][k] == arr[1][k]) {
            continue;
        } else {
            if (arr[0][k] == 0 || arr[1][k] == 0) {
                ans += arr[0][k] + arr[1][k];
            } else {
                ans += abs(arr[0][k] - arr[1][k]);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}