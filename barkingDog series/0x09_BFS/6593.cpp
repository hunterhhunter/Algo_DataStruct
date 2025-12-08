#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 배열 인덱스 접근을 위해 zyx 순으로 설계
struct coordinate
{
    int z;
    int y;
    int x;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        // 층수 l, 행 r, 열 c
        int l, r, c; cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0) {break;}

        vector<vector<vector<char>>> map(l, vector<vector<char>>(r, vector<char>(c, ' ')));
        vector<vector<vector<int>>> visit(l, vector<vector<int>>(r, vector<int>(c, -1)));

        queue<coordinate> q;
        coordinate answer;

        int dx[6] = {1, -1, 0, 0, 0, 0};
        int dy[6] = {0, 0, 1, -1, 0, 0};
        int dz[6] = {0, 0, 0, 0, 1, -1};

        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    char tmp;
                    cin >> tmp;
                    
                    if (tmp == 'S') {
                        q.push({i, j, k});
                        visit[i][j][k] = 1;
                    } else if (tmp == 'E') {
                        answer = {i, j, k};
                    }
                    
                    map[i][j][k] = tmp;
                }
            }
        }

        bool flag = true;

        // BFS 시작
        while (!q.empty())
        {
            coordinate cur = q.front();
            q.pop();

            if (cur.z == answer.z && cur.y == answer.y && cur.x == answer.x) {
                cout << "Escaped in " <<visit[cur.z][cur.y][cur.x]-1 << " minute(s).\n";
                flag = false;
                break;
            }

            for (int i=0; i<6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];

                if (nz < 0 || nz >= l) {continue;}
                if (ny < 0 || ny >= r) {continue;}
                if (nx < 0 || nx >= c) {continue;}
                if (map[nz][ny][nx] == '#') {continue;}
                if (visit[nz][ny][nx] != -1) {continue;}

                visit[nz][ny][nx] = visit[cur.z][cur.y][cur.x]+1;
                q.push({ nz, ny, nx });
            }
        }
        
        if (flag) {
            cout << "Trapped!\n";
        }
    }

    return 0;
}