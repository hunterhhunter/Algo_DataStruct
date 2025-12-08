#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    vector<vector<short>> map(n, vector<short>(n, 0));
    
    int max_height = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            short tmp; cin >> tmp;

            max_height = max(max_height, (int)tmp);

            map[i][j] = tmp;
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<int> answer;

    // 전략 1. 높이 0부터 가장 높은 높이까지 순회하며 bfs로 안전영역 개수 구하고 vector에 push
    // 가장 높은 높이까지 올라가면 다 잠기니까 -1까지만
    for (int height=0; height < max_height; height++) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int ans = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                // 방문 X + 안 잠긴 경우
                if (!visit[i][j] && map[i][j] > height) {
                    q.push({ i, j });
                    visit[i][j] = true;
                    ans++;
                    
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        

                        for (int k=0; k<4; k++) {
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];

                            if (ny < 0 || ny >= n) {continue;}
                            if (nx < 0 || nx >= n) {continue;}
                            if (visit[ny][nx]) {continue;}
                            if (map[ny][nx] <= height) {continue;}

                            q.push({ ny, nx });
                            visit[ny][nx] = true;
                        }
                    }
                }
            }
        }

        // 해당 높이 순회 끝난 후 answer에 ans push
        answer.push_back(ans);
    }

    vector<int>::iterator max_ele = max_element(answer.begin(), answer.end());
    int max_cnt = *max_ele;

    cout << max_cnt << "\n";
    return 0;
}