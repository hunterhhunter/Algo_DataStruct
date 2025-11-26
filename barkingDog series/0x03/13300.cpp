#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 2 X 7 array
    vector<vector<int>> arr(2, vector<int>(7, 0));

    int n, k, sex, grade, ans = 0;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> sex >> grade;
        arr[sex][grade]++;
    }

    for (int i=0; i<2; i++) {
        for (int j=1; j<7; j++) {
            if (arr[i][j] % k == 0) {
                ans += arr[i][j] / k;
            } else {
                ans += (arr[i][j] / k) + 1;
            }
        }
    }

    cout << ans << "\n";
}