#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<char>> painting(n, vector<char>(n));
    vector<vector<bool>> visit1(n, vector<bool>(n, false));
    vector<vector<bool>> visit2(n, vector<bool>(n, false));

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // 일반인, 색맹
    int ans1 = 0, ans2 = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> painting[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // 일반인 bfs
            if (!visit1[i][j]) {
                q1.push({ i, j });
                visit1[i][j] = true;

                while (!q1.empty()) {
                    pair<int, int> cur = q1.front();
                    q1.pop();

                    for (int k=0; k<4; k++) {
                        int ny = cur.first+dy[k];
                        int nx = cur.second+dx[k];

                        if (ny < 0 || ny >= n) {continue;}
                        if (nx < 0 || nx >= n) {continue;}
                        if (painting[ny][nx] != painting[cur.first][cur.second]) {continue;}
                        if (visit1[ny][nx]) {continue;}

                        visit1[ny][nx] = true;
                        q1.push({ ny, nx });
                    }
                }
                ans1++;
            }

            // 색맹인 bfs
            if (!visit2[i][j]) {
                q2.push({ i, j });
                visit2[i][j] = true;

                while (!q2.empty()) {
                    pair<int, int> cur = q2.front();
                    q2.pop();

                    for (int k=0; k<4; k++) {
                        int ny = cur.first+dy[k];
                        int nx = cur.second+dx[k];

                        if (ny < 0 || ny >= n) {continue;}
                        if (nx < 0 || nx >= n) {continue;}
                        // 색맹인의 경우 R, G인 경우 ny, nx가 B면 conti, 아니면 진행
                        if (painting[cur.first][cur.second] == 'G' || painting[cur.first][cur.second] == 'R') {
                            if (painting[ny][nx] == 'B') {
                                continue;
                            }
                        } else {
                            if (painting[ny][nx] != painting[cur.first][cur.second]) {
                                continue;
                            }
                        }
                        if (visit2[ny][nx]) {continue;}

                        visit2[ny][nx] = true;
                        q2.push({ ny, nx });
                    }
                }
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2 << "\n";
    return 0;
}