#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<int> floor(f, -1);

    queue<int> q;

    q.push(s-1);
    floor[s-1] = 0;
    int dx[2] = {u, -d};

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i=0; i<2; i++) {
            int nx = cur + dx[i];

            if (nx < 0 || nx >= f) {continue;}
            if (floor[nx] != -1) {continue;}

            q.push(nx);
            floor[nx] = floor[cur]+1;
        }
    }

    if (floor[g-1] == -1) {
        cout << "use the stairs";
    } else {
        cout << floor[g-1];
    }

    return 0;
}