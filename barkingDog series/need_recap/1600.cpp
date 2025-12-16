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

bool layer_check(vector<vector<vector<int>>>& visit, int layer, int x, int y, int future) {
    int flag = 0;
    if (future == 1) {layer++;}

    for (int i=0; i<layer; i++) {
        if (visit[i][y][x] != -1) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k; cin >> k;
    int w, h; cin >> w >> h;

    if (w == 1 && h == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> map(h+1, vector<int>(w+1, 0));
    // 각 층 수가 원숭이가 점프를 뛴 횟수
    vector<vector<vector<int>>> visit(k+5, vector<vector<int>>(h+5, vector<int>(w+5, -1)));


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

    q.push({ 0, 0, 0 });
    visit[0][0][0] = 0;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        
        // 말처럼 움직일 여력이 남았으면 말 BFS 진행
        if (cur.remain != k) {
            for (int i=0; i<8; i++) {
                int nx = cur.x + horse_x[i];
                int ny = cur.y + horse_y[i];
                
                if (ny < 0 || ny >= h) { continue; }
                if (nx < 0 || nx >= w) { continue; }
                if (visit[cur.remain+1][ny][nx] != -1) { continue; }
                if (map[ny][nx] == 1) { continue; }

                if (ny == h-1 && nx == w-1) {cout << visit[cur.remain][cur.y][cur.x]+1; return 0;}
                int flag = 0;
                // 이전 움직임 중 현재 움직임보다 빠르게 움직인 경우가 있는지 검사
                flag = layer_check(visit, cur.remain, nx, ny, 1);
                if (flag == 1) { continue; }
                
                q.push({ ny, nx, cur.remain+1 });
                visit[cur.remain+1][ny][nx] = visit[cur.remain][cur.y][cur.x]+1;
            }
        }
        // 일반 BFS 진행
        for (int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (ny < 0 || ny >= h) {continue;}
            if (nx < 0 || nx >= w) {continue;}
            if (map[ny][nx] == 1) {continue;}
            if (visit[cur.remain][ny][nx] != -1) { continue; }

            if (ny == h-1 && nx == w-1) {cout << visit[cur.remain][cur.y][cur.x]+1; return 0;}

            int flag = 0;
            // 이전 레이어에서 더 일찍 온 경우가 있는지 확인
            flag = layer_check(visit, cur.remain, nx, ny, 0);
            if (flag == 1) {continue;}

            q.push({ ny, nx, cur.remain });
            visit[cur.remain][ny][nx] = visit[cur.remain][cur.y][cur.x]+1;
        }
    }

    cout << -1;
    return 0;
}