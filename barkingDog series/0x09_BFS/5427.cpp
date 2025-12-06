#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    while (n--) {
        int w, h;
        cin >> w >> h;

        vector<vector<char>> map(h, vector<char>(w, '0'));
        vector<vector<int>> visit1(h, vector<int>(w, 0));
        vector<vector<int>> visit2(h, vector<int>(w, 0));


        queue<pair<int, int>> q;

        // 상근이 좌표
        int s_x, s_y;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                char tmp; cin >> tmp;

                if (tmp == '@') {
                    s_y = i, s_x = j;
                } else if (tmp == '*') {
                    q.push({ i, j });
                    visit1[i][j] = 1;
                }

                map[i][j] = tmp;
            }
        }

        // 불에 대한 BFS
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int ny = cur.first+dy[i];
                int nx = cur.second+dx[i];

                if (ny < 0 || ny >= h) {continue;}
                if (nx < 0 || nx >= w) {continue;}
                if (map[ny][nx] == '#') {continue;}
                if (visit1[ny][nx] != 0) {continue;}

                visit1[ny][nx] = visit1[cur.first][cur.second]+1;
                q.push({ ny, nx });
            }
        }

        int ans = 0;

        // 상근이 BFS
        q.push({ s_y, s_x });
        visit2[s_y][s_x] = 1;
        bool flag = true;

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                int ny = cur.first+dy[i];
                int nx = cur.second+dx[i];

                // 벗어난 것
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                    cout << visit2[cur.first][cur.second] << "\n";
                    flag = false;
                    break;
                }
                
                if (map[ny][nx] == '#') {continue;}
                if (visit2[ny][nx] != 0) {continue;}
                // 상근이는 불이 붙으려는 or 붙은 칸 이동 X
                if (visit1[ny][nx] != 0 && visit1[ny][nx] <= visit2[cur.first][cur.second]+1) {
                    continue;
                }


                visit2[ny][nx] = visit2[cur.first][cur.second]+1;
                q.push({ ny, nx });
            }

            if (!flag) {break;}
            // for (int i=0; i<h; i++) {
            //     for (int j=0; j<w; j++) {
            //         cout << visit1[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "==============\n";

            // for (int i=0; i<h; i++) {
            //     for (int j=0; j<w; j++) {
            //         cout << visit2[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "==============\n";
        }

        if (flag) {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}