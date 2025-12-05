#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> c >> r;

    vector<vector<char>> map(c, vector<char>(r, '0'));
    vector<vector<int>> jihun(c, vector<int>(r, 1));
    vector<vector<int>> fire(c, vector<int>(r, 1));

    queue<pair<int ,int>> jihun_q;
    queue<pair<int, int>> fire_q;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<pair<int, int>> sides;

    bool print = true;

    // 기본 접근 로직
    // 1. nx, ny가 모서리 도착시 최소 거리가 얼마인지 기록? -> 얘는 아닌듯
    // 2. 불과 지훈이가 겹치는지 확인하는게? -> 얘먼저
        // 불 먼저 확산? 지훈이 먼저 이동? -> 지훈이 먼저 가보자
        // 불인지 지훈이인지 알아야하는거 아님? -> map으로 구분
        // 불 확산하고 지훈이가 갈 수 있는지 확인하면? -> 못가면 IMPOSSIBLE, 갈 수 있으면 증가
    // 3. BFS를 불 따로 지훈이 따로하고 탈출 위치중 가장 빠른 위치의 불의 값이 탈출 시간보다 작으면 탈출

    int jy, jx;

    for (int i=0; i<c; i++) {
        for (int j=0; j<r; j++) {
            char tmp;
            cin >> tmp;

            if (tmp == 'J' ) {
                if (i == 0 || i==c-1 || j == 0 || j==r-1) {
                    cout << 1 << "\n";
                    return 0;
                }
                jihun_q.push({ i, j });
            }
            if (tmp == 'F') {
                fire_q.push({ i, j });
            }

            map[i][j] = tmp;

            if (tmp == '.') {
                if (i == 0 || i==c-1) {
                    sides.push_back({ i, j });
                    continue;
                }
                if (j == 0 || j==r-1) {
                    sides.push_back({ i, j });
                    continue;
                }
            }
        }
    }

    // 불 확산
    while (!fire_q.empty()) {
        pair<int, int> current = fire_q.front();
        fire_q.pop();

        for (int i=0; i<4; i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (ny < 0 || ny >= c) {
                continue;
            }
            if (nx < 0 || nx >= r) {
                continue;
            }
            if (map[ny][nx] == '#' || map[ny][nx] == 'F') {
                continue;
            }
            if (fire[ny][nx] != 1) {
                continue;
            }
            fire[ny][nx] = fire[current.first][current.second]+1;
            fire_q.push({ ny, nx });
        }
    }

    // 지훈 이동
    while (!jihun_q.empty()) {
        pair<int, int> current = jihun_q.front();
        jihun_q.pop();

        for (int i=0; i<4; i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (ny < 0 || ny >= c) {
                continue;
            }
            if (nx < 0 || nx >= r) {
                continue;
            }
            if (map[ny][nx] == '#' || map[ny][nx] == 'J') {
                continue;
            }
            if (jihun[ny][nx] != 1) {
                continue;
            }
            jihun[ny][nx] = jihun[current.first][current.second]+1;
            jihun_q.push({ ny, nx });
        }
    }

    if (print) {
        for (int i=0; i<c; i++) {
            for (int j=0; j<r; j++) {
                cout << fire[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "=============================\n";
        
        for (int i=0; i<c; i++) {
            for (int j=0; j<r; j++) {
                cout << jihun[i][j] << " ";
            }
            cout << "\n";
        }
    }


    int ans = 2100000000;
    pair<int, int> ans_yx;
    vector<pair<int, int>> answer;

    // 사이드 다 돌았을 때 지훈이 최소 탈출시간
    while (!sides.empty()) {
        pair<int, int> cur = sides.back();
        sides.pop_back();

        int y = cur.first, x = cur.second;

        if (ans >= jihun[y][x]) {
            if (jihun[y][x] != 1) {
                if (jihun[y][x] < fire[y][x] || fire[y][x] == 1) {
                    answer.push_back({ y, x });
                    ans = min(ans, jihun[y][x]);
                }
            }
        }
    }

    while (!answer.empty()) {
        pair<int, int> cur = answer.back();
        answer.pop_back();
        int tmp_ans = jihun[cur.first][cur.second];
        ans_yx.first = cur.first, ans_yx.second = cur.second;

        // 그 위치에서 불의 확산시간이 더 작으면 탈출
        if (tmp_ans != 1 && tmp_ans != 2100000000 && tmp_ans == ans) {
            if (fire[ans_yx.first][ans_yx.second] == 1) {
                cout << tmp_ans;
                return 0;
            } else {
                if (tmp_ans < fire[ans_yx.first][ans_yx.second]) {
                    cout << tmp_ans;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}