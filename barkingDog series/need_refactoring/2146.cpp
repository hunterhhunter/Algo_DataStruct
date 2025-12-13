#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
    int y;
    int x;
    bool is_same;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> map(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    
    vector<vector<int>> visit(n, vector<int>(n, -1));
    vector<vector<int>> visit2(n, vector<int>(n, -1));

    queue<pos> q;
    vector<int> distance;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int separator = 0;
    // 접근: 큐를 2개 만들어서 내륙용, 해안용으로
    // 대륙 먼저 BFS -> 해안선 만나면 q2에 저장
    // 해안선 BFS 할 때는 다른 대륙 만나면 마킹 안하고 거리만 저장 -> min_element로 출력
    for (int i = 0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (map[i][j] == 1 && visit[i][j] == -1 && visit2[i][j] == -1) {
                queue<pos> q2;
                visit2[i][j] = separator;
                visit[i][j] = separator;
                q.push({ i, j, true });

                // 대륙 먼저 bfs
                while (!q.empty()) {
                    pos cur = q.front();
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int ny = cur.y + dy[k];
                        int nx = cur.x + dx[k];

                        if (ny < 0 || ny >= n) {continue;}
                        if (nx < 0 || nx >= n) {continue;}
                        if (visit2[ny][nx] != -1) {continue;}
                        if (map[ny][nx] == 0) {
                            // 0일경우 q2에 push
                            q2.push({ ny, nx, false });
                            visit2[ny][nx] = visit2[cur.y][cur.x]+1;
                        } else {
                            // 같은 대륙의 경우 그냥 전진
                            q.push({ ny, nx, true });
                            visit2[ny][nx] = separator;
                            visit[ny][nx] = separator;
                        }
                    }
                    
                }

                // 거리 구하기 bfs
                while (!q2.empty()) {
                    pos cur = q2.front();
                    q2.pop();

                    for (int k=0; k<4; k++) {
                        int ny = cur.y + dy[k];
                        int nx = cur.x + dx[k];

                        if (ny < 0 || ny >= n) {continue;}
                        if (nx < 0 || nx >= n) {continue;}
                        if (visit2[ny][nx] != -1) {continue;}
                        if (map[ny][nx] == 0) {
                            // 0일경우 q2에 push
                            q2.push({ ny, nx, false });
                            visit2[ny][nx] = visit2[cur.y][cur.x]+1;
                        } else {
                            if (visit2[ny][nx] != separator) {
                                distance.push_back(visit2[cur.y][cur.x] - separator);
                            }
                        }
                    }
                    
                }
                // cout << "===================================\n";
                // for (int i=0; i<n; i++) {
                //     for (int j=0; j<n; j++) {
                //         cout << visit2[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << "===================================\n";
                
                // 지도 초기화
                visit2 = visit;
                separator++;
                // for (int i=0; i<n; i++) {
                //     for (int j=0; j<n; j++) {
                //         cout << visit2[i][j] << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << "===================================\n";
            }
        }
    }
    auto ans = min_element(distance.begin(), distance.end());
    
    cout << *ans << "\n";

    return 0;
}