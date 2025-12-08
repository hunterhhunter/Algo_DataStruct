#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> paper(m, vector<int>(n, 0));
    vector<vector<bool>> visit(m, vector<bool>(n, false));

    queue<pair<int, int>> q;
    vector<int> extent;
    

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // 굳이 좌표변환 해줄필요 없음
    while (k--) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int i=lx; i<rx; i++) {
            for (int j=ly; j<ry; j++) {
                paper[j][i] = 1;
            }
        }

        // for (int i=0; i<m; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << paper[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (!visit[i][j] && paper[i][j] != 1) {
                int ans = 0;
                q.push({ i, j });
                visit[i][j] = true;

                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    ans++;

                    for (int k=0; k<4; k++) {
                        int nx = cur.second+dx[k];
                        int ny = cur.first+dy[k];

                        if (nx < 0 || nx >= n) {continue;}
                        if (ny < 0 || ny >= m) {continue;}
                        if (visit[ny][nx]) {continue;}
                        if (paper[ny][nx] == 1) {continue;}

                        visit[ny][nx] = true;
                        q.push({ ny, nx });
                    }
                }
                // 넓이 push
                extent.push_back(ans);
            }
        }
    }

    sort(extent.begin(), extent.end());
    cout << extent.size() << "\n";
    for (auto t : extent) {
        cout << t << " ";
    }

    return 0;
}