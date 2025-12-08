#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> count_0(int n, int m, const vector<vector<int>>& map, const vector<pair<int, int>>& ice) {
    vector<vector<int>> result(n, vector<int>(m, 0));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (auto cor : ice) {
        int tmp = 0;
        for (int i=0; i<4; i++) {
            int nx = cor.second + dx[i];
            int ny = cor.first + dy[i];

            if (ny < 0 || ny >= n) {continue;}
            if (nx < 0 || nx >= m) {continue;}
            if (map[ny][nx] == 0) {
                tmp++;
            }
        }
        result[cor.first][cor.second] = tmp;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<pair<int, int>> ice;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp != 0) {
                ice.push_back({i, j});
            }
            map[i][j] = tmp;
        }
    }

    // 접근 1. 우선 0과 인접한 개수를 구하는 코드 + 그 때 BFS 돌려서 빙산 몇 개 되는지 찾는 코드

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int ans = 0;

    while (true) {
        // 개수확인
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        int tmp = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (map[i][j] != 0 && !visit[i][j]) {
                    tmp++;
                    q.push({ i, j });
                    visit[i][j] = true;

                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();

                        for (int k=0; k<4; k++) {
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];

                            if (ny < 0 || ny >= n) {continue;}
                            if (nx < 0 || nx >= m) {continue;}
                            if (visit[ny][nx]) {continue;}
                            if (map[ny][nx] == 0) {continue;}

                            q.push({ ny, nx });
                            visit[ny][nx] = true;
                        }
                    }
                }
            }
        }

        // 여기서 분리되면 -> 출력 후 return
        if (tmp > 1) {
            cout << ans;
            return 0;
        }

        // 빙산 없으면 탈출
        if (tmp == 0) {
            break;
        }
        
        // 빙산 녹아내리게
        vector<vector<int>> after_year = count_0(n, m, map, ice);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                map[i][j] = max(0, map[i][j]-after_year[i][j]);
            }
        }

        // 녹아내린 후 +1년
        ans++;
    }

    cout << 0;
    return 0;
}