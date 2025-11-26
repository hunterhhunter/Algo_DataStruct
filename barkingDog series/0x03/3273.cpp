#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // max 100000 - nlogn
    int n, tmp, x;
    cin >> n;

    int ans = 0;
    vector<int> arr(n, 0);

    for (int i=0; i<n; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    sort(arr.begin(), arr.end());

    // for (int i=0;i<n;i++) {
    //     cout << arr[i] << " ";
    // }

    cin >> x;

    int p1 = 0, p2 = n-1;

    while (p1 < p2) {
        tmp = arr[p1] + arr[p2];
        if (tmp > x) {
            p2--;
        } else if (tmp < x) {
            p1++;
        } else {
            ans++;
            p1++;
        }
    }
    
    cout << ans << "\n";
}