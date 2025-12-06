#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct location
{
    int x;
    int y;
    int z;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, h; cin >> m >> n >> h;

    vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m, 0)));
    vector<vector<vector<int>>> visit(h, vector<vector<int>>(n, vector<int>(m, 0)));


    queue<location> q;

    // 3차원 인덱스 삑안나게 조심
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                int tmp;
                cin >> tmp;

                if (tmp == 1) {
                    q.push({ k, j, i });
                    visit[i][j][k] = 1;
                } else if (tmp == -1) {
                    visit[i][j][k] = -1;
                }
                box[i][j][k] = tmp;
            }
        }
    }

    int nx[6] = {1, -1, 0, 0, 0, 0};
    int ny[6] = {0, 0, 1, -1, 0, 0};
    int nz[6] = {0, 0, 0, 0, 1, -1};

    while (!q.empty()) 
    {
        location cur = q.front();
        q.pop();

        for (int i=0; i<6; i++) {
            int dz = cur.z+nz[i];
            int dy = cur.y+ny[i];
            int dx = cur.x+nx[i];
            
            if (dz < 0 || dz >= h) {continue;}
            if (dy < 0 || dy >= n) {continue;}
            if (dx < 0 || dx >= m) {continue;}

            if (visit[dz][dy][dx] != 0) {continue;}
            if (box[dz][dy][dx] == -1) {continue;}

            visit[dz][dy][dx] = visit[cur.z][cur.y][cur.x]+1;
            q.push({ dx, dy, dz });
        }
    }
    
    int ans = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++) {
                if (visit[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, visit[i][j][k]);
            }
        }
    }
    cout << ans-1;
    return 0;
}