#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;

    vector<vector<int>> table(n+1, vector<int>(k+1, 0));
    vector<int> weight;
    vector<int> value;

    for (int i=1; i<=n; i++) {
        int wei, val; cin >> wei >> val;
        weight.push_back(wei);
        value.push_back(val);
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            // i, j 정의: i번째 물건까지 고려할 때 j무게에서 얻을 수 있는 최대 가치
            // 고려하는 상황: 이번 물건 챙길 때 or 안 챙길 떄
            // 이번 물건 안 챙길 떄: table[i-1][j]
            // 이번 물건 챙길 떄: table[i-1][j - weight[i-1]] + value[i-1]
            int changgim_weight = j - weight[i-1];
            int changgim_value = changgim_weight < 0 ? 0 : value[i-1];
            if (changgim_weight < 0) {
                changgim_weight = 0;
            }
            table[i][j] = max(table[i-1][j], table[i-1][changgim_weight] + changgim_value);

            
        }
        // for (int i=0; i<=n; i++) {
        //         for (int j=0; j<=k; j++) {
        //             cout << table[i][j] << " ";
        //         }
        //         cout << "\n";
        //     }
        //     cout << "====================================\n";
    }

    cout << table[n][k];
    return 0;
}