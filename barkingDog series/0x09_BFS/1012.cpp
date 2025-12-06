#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while (n--) {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> map(n, vector<int>(m, 0));
        vector<vector<bool>> visit(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int ans = 0;

        while (k--) {
            int x, y;
            cin >> x >> y;

            map[y][x] = 1;
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (map[i][j] == 1 && !visit[i][j]) {
                    q.push({ i, j });
                    visit[i][j] = true;
                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();

                        for (int idx=0; idx<4; idx++) {
                            int ny = current.first+dy[idx];
                            int nx = current.second+dx[idx];

                            if (ny < 0 || ny >= n) {continue;}
                            if (nx < 0 || nx >= m) {continue;}
                            if (map[ny][nx] != 1) {continue;}
                            if (visit[ny][nx]) {continue;}
                            
                            visit[ny][nx] = true;
                            q.push({ ny, nx });
                        }
                    }
                    ans++;
                }
            }
        }

        cout << ans<< "\n";
    }

    return 0;
}