#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos
{
    int y;
    int x;
    int remain;
};


int main() {
    int k; cin >> k;
    int w, h; cin >> w >> h;

    vector<vector<int>> map(h, vector<int>(w, 0));
    vector<vector<int>> visit(h, vector<int>(w, -1));


    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> map[i][j];
        }
    }

    queue<pos> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int horse_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int horse_y[8] = {1, -1, 2, -2, 2, -2, 1, -1};

    q.push({ 0, 0, k });
    visit[0][0] = 0;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        if (cur.remain > 0) {
            int flag = 0;
            for (int i=0; i<8; i++) {
                int nx = cur.x + horse_x[i];
                int ny = cur.y + horse_y[i];
                
                if (ny < 0 || ny >= h) { flag++; continue; }
                if (nx < 0 || nx >= w) { flag++; continue; }
                if (visit[ny][nx] != -1) { flag++; continue; }
                if (map[ny][nx] == 1) { flag++; continue; }
                
                q.push({ ny, nx, cur.remain-1 });
                visit[ny][nx] = visit[cur.y][cur.x]+1;
            }
            if (flag == 8) {
                q.push({ cur.y, cur.x, cur.remain });
            }
        } else {
            for (int i=0; i<4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                
                if (ny < 0 || ny >= h) {continue;}
                if (nx < 0 || nx >= w) {continue;}
                if (map[ny][nx] == 1) {continue;}
                if (visit[ny][nx] != -1) {continue;}

                q.push({ ny, nx, 0 });
                visit[ny][nx] = visit[cur.y][cur.x]+1;
            }
        }
    }

    cout << "================\n";
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }

    cout << visit[h-1][w-1];
    return 0;
}