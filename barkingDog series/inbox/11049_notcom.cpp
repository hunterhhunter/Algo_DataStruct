#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int tmp = n;
    vector<vector<int>> table(n+1, vector<int>(n+1, INT_MAX));
    vector<pair<int, int>> matrix;

    while (tmp--) {
        int f, s;
        cin >> f >> s;
        matrix.push_back({ f, s });
        table[tmp][tmp] = 0;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n-i+1; j++) {
            int k = i + j;
            // j, k를 채워야함.
            cout << i  << " " << j << " " << k << "\n";

            for (int a=j; a<k-1; a++) {
                cout << a << " " << j << "\n";
            }
        }
    }

    return 0;
}