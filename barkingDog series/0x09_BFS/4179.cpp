#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(c, vector<char>(r, '0'));
    vector<vector<int>> visit(c, vector<int>(r, 1));

    queue<pair<char, pair<int ,int>>> q;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<pair<int, int>> sides;

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
                jy = i;
                jx = j;
            } else if (tmp == 'F') {
                q.push({ 'F', { i, j }});
            }

            map[i][j] = tmp;
            if (tmp == '.') {

                if (i == 0 || i==c-1) {
                    visit[i][j] = 2100000000;
                    sides.push_back({ i, j });
                    continue;
                }
                if (j == 0 || j==r-1) {
                    visit[i][j] = 2100000000;
                    sides.push_back({ i, j });
                    continue;
                }
            }
        }
    }

    sides.push_back({ jy, jx });
    // 명시적으로 지훈이가 가장 늦게 움직이도록
    q.push({ 'J', { jy, jx }});

    while (!q.empty()) {
        pair<char, pair<int, int>> current = q.front();
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = current.second.first + dy[i];
            int nx = current.second.second + dx[i];

            if (ny < 0 || ny >= c) {
                continue;
            }
            if (nx < 0 || nx >= r) {
                continue;
            }
            if (map[ny][nx] == '#' || map[ny][nx] == 'F') {
                continue;
            }

            // 불 확산의 경우
            if (current.first == 'F') {
                q.push({'F', { ny, nx }});
                map[ny][nx] = 'F';
            }
            // 지훈이의 경우
            if (current.first == 'J') {
                // 그게 아니면 움직임
                visit[ny][nx] = visit[current.second.first][current.second.second]+1;
                map[ny][nx] = 'J';
                q.push({ 'J', { ny, nx }});
            }
        }

        for (int i=0; i<c; i++) {
            for (int j=0; j<r; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
                for (int i=0; i<c; i++) {
            for (int j=0; j<r; j++) {
                cout << visit[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "---------------------------\n";
    }
    int ans = 2100000000;
    // 다 끝났을 떄 sides 중에서 2100000000이 아닌 수중 최소값이 정답 -> 전부 0이면 IMPOSSIBLE
    for (pair<int, int> t: sides) {
        ans = min(ans, visit[t.first][t.second]);
    }

    if (ans == 2100000000) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}