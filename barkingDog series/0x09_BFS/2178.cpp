#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<int>> visit(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;

        for (int j=0;j<m;j++) {
            map[i][j] = (int) tmp[j] - '0';
        }
    }

    queue<pair<int, int>> q; // 2nd dim, 1st dim

    q.push({0, 0});
    visit[0][0] = true;

    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i=0;i<4;i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (ny < 0 || ny >= n) {
                continue;
            }
            if (nx < 0 || nx >= m) {
                continue;
            }
            if (map[ny][nx] == 0) {
                continue;
            }
            if (visit[ny][nx] != 0) {
                continue;
            }

            q.push({ ny, nx });
            visit[ny][nx] = visit[current.first][current.second]+1;
        }
    }

    cout << visit[n-1][m-1] << "\n";
    return 0;
}