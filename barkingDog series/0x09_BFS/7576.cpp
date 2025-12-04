#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;

    vector<vector<int>> box(n, vector<int>(m, 0));
    vector<vector<int>> visit(n, vector<int>(m, 0));

    int x, y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            visit[i][j] = tmp;

            if (tmp == 1) {
                q.push({i, j});
                visit[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (ny < 0 || ny >= n) {
                continue;
            }
            if (nx < 0 || nx >= m) {
                continue;
            }
            if (visit[ny][nx] != 0) {
                continue;
            }

            visit[ny][nx] = visit[current.first][current.second]+1;
            q.push({ ny, nx });
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (visit[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            ans = max(ans, visit[i][j]);
        }
    }

    cout << ans-1 << "\n";
    return 0;
}