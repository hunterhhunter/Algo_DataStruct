#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> map(200001, -1);
    // 
    vector<vector<pair<int, int>>> rt(200001, vector<pair<int, int>>());

    queue<int> q;
    map[n] = 0;
    rt[n].push_back({ n, 0 });
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : {cur+1, cur-1, cur*2}) {
            if (nxt < 0 || nxt > 200000) {continue;}
            if (rt[nxt].empty()) {
                rt[nxt].push_back({ cur, map[cur]+1 });
                q.push(nxt);
                map[nxt] = map[cur]+1;
            } else {
                if (rt[nxt][rt[nxt].size()-1].second >= map[cur]+1) {
                    rt[nxt].push_back({ cur, map[cur]+1 });
                    q.push(nxt);
                    map[nxt] = map[cur]+1;
                } else {
                    continue;
                }
            }
        }
    }

    cout << map[k] << "\n";

    
    int ans = 0;
    while (true) {
        int tmp = rt[k].back().second;
        ans++;
        rt[k].pop_back();
        if ( rt[k].empty() || tmp < rt[k].back().second) {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}