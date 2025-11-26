#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // a = 97

    for (int i=0; i<n; i++) {
        vector<vector<int>> arr(2, vector<int>(26, 0));
        
        string a, b;
        cin >> a >> b;

        for (int j=0; j<a.length(); j++) {
            arr[0][(int)a[j]-97]++;
        }

        for (int j=0; j<b.length(); j++) {
            arr[1][(int)b[j]-97]++;
        }

        bool flag = false;
        for (int k=0; k<26; k++) {
            if (arr[0][k] != arr[1][k]) {
                flag = true;
            }
        }

        if (flag) {
            cout << "Impossible" << "\n";
        } else {
            cout << "Possible" << "\n";
        }
    }
    return 0;
}