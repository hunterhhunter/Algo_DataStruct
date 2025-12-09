#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    string first, second;

    cin >> first;
    cin >> second;

    vector<vector<int>> table(first.length()+1, vector<int>(second.length()+1, INT_MAX));

    table[0][0] = 0;
    for (int i=1; i<=first.length(); i++) {
        table[i][0] = i;
    }
    for (int i=1; i<=second.length(); i++) {
        table[0][i] = i;
    }

    // for (int i=0; i<=first.length(); i++) {
    //     for (int j=0; j<=second.length(); j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // table[i][j]는 첫 번째 문자열 i번째에서 두번째 문자열의 j까지 바꾸는데 드는 최소 편집 비용
    for (int i=1; i<=first.length(); i++) {
        for (int j=1; j<=second.length(); j++) {
            int tmp = first[i-1] == second[j-1] ? 0 : 1;
            table[i][j] = min({table[i][j], table[i-1][j]+1, table[i][j-1]+1, table[i-1][j-1] + tmp});
        }

        // for (int i=0; i<=first.length(); i++) {
        //     for (int j=0; j<=second.length(); j++) {
        //         cout << table[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    cout << table[first.length()][second.length()];

    return 0;
}