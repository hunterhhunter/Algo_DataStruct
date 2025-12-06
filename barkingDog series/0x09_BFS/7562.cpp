#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    while (n--) {
        int l; cin >> l;

        queue<pair<int, int>> q;
        vector<vector<int>> map(l, vector<int>(l, 0));

        int x, y;
        cin >> x >> y;

        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

        map[y][x] = 1;
        q.push({ y, x });

        while (!q.empty()) 
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int i=0; i<8; i++) {
                int ny = cur.first+dy[i];
                int nx = cur.second+dx[i];

                if (ny < 0 || ny >= l) {continue;}
                if (nx < 0 || nx >= l) {continue;}

                if (map[ny][nx] != 0) {continue;}

                map[ny][nx] = map[cur.first][cur.second]+1;
                q.push({ ny, nx });
            } 
        }
        int o_x, o_y;
        cin >> o_x >> o_y;

        cout << map[o_y][o_x]-1<< "\n";
    }

    return 0;
}