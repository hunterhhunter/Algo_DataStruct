#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n; cin >> n;

    while (n--) {
        int paper; cin >> paper;
        vector<int> papers(paper+1, 0);
        vector<vector<int>> table(paper+1, vector<int>(paper+1, 0));

        for (int i=1; i<=paper; i++) {
            int tmp;
            cin >> tmp;

            papers[i] = tmp + papers[i-1];
        }

        for (int l=2; l<=paper; l++) {
            // 2 -> 1 2 3
            // 3 -> 1 2
            // 4 -> 1
            for (int i=1; i<=paper-l+1; i++) {
                // 2, 1 -> 2
                // 2, 2 -> 3
                // 2, 3 -> 4
                // 3, 1 -> 3
                // 3, 2 -> 4
                // 4, 1 -> 4
                int j = i + l - 1;
                table[i][j] = INT_MAX;
                // 분할점이 어디인지
                for (int k = i; k < j; k++) {
                    // 분할했을 때 최솟값 테이블 참조 + 병합비용을 해줘야함.
                    int tmp = table[i][k] + table[k+1][j] + papers[j] - papers[i-1];
                    table[i][j] = min(table[i][j], tmp);
                }
                // for (int i=1; i<=paper; i++) {
                //     for (int j=1; j<=paper; j++) {
                //         cout << table[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
            }
        }

        // for (int i=0; i<=paper; i++) {
        //     for (int j=0; j<=paper; j++) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << table[1][paper] << "\n";
    }
    return 0;
}