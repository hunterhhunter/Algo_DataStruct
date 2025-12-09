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
    vector<int> matrix(n+1);

    for (int i=1; i<=n; i++) {
        int r, c; cin >> r >> c;
        
        if (i == 1) {
            matrix[0] = r;
        }
        matrix[i] = c;

        table[i][i] = 0;
    }

    

    // table[i][j]가 의미하는 것은 i행렬부터 j행렬까지 곱할 때 최솟값
    // 대각선(계산 길이) 지정
    for (int l=2; l <= n; l++) {
        // 계산 시작 행렬 번호 지정
        for (int i=1; i<=n-l+1; i++) {
            // 계산 끝나는 행렬 번호 지정
            int j = i + l - 1;
            table[i][j] = INT_MAX;

            // 몇번에서 분할해서 계산할건지
            for (int k=i; k < j; k++) {
                // cout << l << " " << i << " " << j << " " << k << "\n";
                // table[i][k]: 
                int tmp = table[i][k] + table[k+1][j] + (matrix[i-1] * matrix[k] * matrix[j]);
                table[i][j] = min(tmp, table[i][j]);
            }
        }
    }
    cout << table[1][n];

    return 0;
}