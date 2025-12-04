#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m, 0));
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> paper[i][j];
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int cnt = 0, extent = 0;

    queue<pair<int, int>> q;

    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            if (visit[y][x] || paper[y][x] == 0) {
                continue;
            }
            int tmp_extent = 0;
            // 방문
            q.push({ y, x });
            visit[y][x] = true;

            while (!q.empty()) {
                pair<int, int> current = q.front();
                q.pop();
                tmp_extent++;
                // 주변 노드 탐색
                for (int k=0; k<4; k++) {
                    int ny = current.first + dy[k];
                    int nx = current.second + dx[k];
                    // ny, nx 범위 한정
                    if (ny < 0 || ny >= n) {
                        continue;
                    }
                    if (nx < 0 || nx >= m) {
                        continue;
                    }
                    if (paper[ny][nx] != 1) {
                        continue;
                    }
                    if (visit[ny][nx]) {
                        continue;
                    }
                    // 방문
                    q.push({ny, nx});
                    visit[ny][nx] = true;
                }
            }
            cnt++;
            extent = max(extent, tmp_extent);
        }
    }

    cout << cnt << "\n" << extent << "\n";

    return 0;
}