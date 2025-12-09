#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

struct pos
{
    int y;
    int x;
    bool broken;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 접근 1. 1인 애들을 하나씩만 제거한 맵 마다 BFS 돌려서 최솟값 찾기
    // 접근 2(검색). 상태를 2개로 나누어 부순경우 안 부순 경우 visit을 2개 생성
    //    -> 0번의 경우 안 부쉈을 때, 1번의 경우 부쉈을 때
    //    -> 부쉈을 때 flag만 잘 넣어주면 BFS이기 떄문에 알아서 잘 상태관리가 됨.    
    int n, m; cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    vector<vector<vector<int>>> visit(n, vector<vector<int>>(m, vector<int>(2, -1)));

    queue<pos> q;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char tmp;
            cin >> tmp;

            map[i][j] = (int)tmp - '0';
        }
    }

    q.push({ 0, 0, false });
    visit[0][0][0] = 1;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        int cur_distance = visit[cur.y][cur.x][cur.broken ? 1 : 0];

        for (int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || ny >= n) {continue;}
            if (nx < 0 || nx >= m) {continue;}
            
            // 현재 맵 진행이 가능할 떄
            if (map[ny][nx] == 0) {
                // 벽 부순적 있는지 확인
                bool next_state_idx = cur.broken ? 1 : 0;
                // 그 위치에 방문한 적이 없으면
                if (visit[ny][nx][next_state_idx] == -1) {
                    // 진행
                    q.push({ ny, nx, next_state_idx });
                    visit[ny][nx][next_state_idx] = cur_distance+1;
                }
            } else if (map[ny][nx] == 1) {
                // 벽이 있는 경우에 부순 적 없을 떄
                if (!cur.broken) {
                    // 심지어 방문도 안했을 떄
                    if (visit[ny][nx][1] == -1) {
                        // 진행
                        visit[ny][nx][1] = cur_distance+1;
                        q.push({ ny, nx, true });
                    }
                }
            }
        }
    }

    int ans1 = visit[n-1][m-1][0], ans2 = visit[n-1][m-1][1];
    if (ans1 != -1) {
        if (ans2 != -1) {
            cout << min(ans1, ans2);
        } else {
            cout << ans1;
        }
    } else {
        if (ans2 != -1) {
            cout << ans2;
        } else {
            cout << -1;
        }
    }

    return 0;
}