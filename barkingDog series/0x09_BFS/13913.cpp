#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos
{
    int x;
    int parent;
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> map(200001, -1);
    // 부모 노드 기록해두는게 핵심
    vector<int> rt(200001, 0);

    queue<int> q;
    map[n] = 0;
    rt[n] = -1;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : {cur+1, cur-1, cur*2}) {
            if (nxt < 0 || nxt > 200000) {continue;}
            if (map[nxt] != -1) {continue;}

            q.push(nxt);
            if (rt[nxt] == 0) {
                rt[nxt] = cur; 
            }
            map[nxt] = map[cur]+1;
        }
    }

    cout << map[k] << "\n";
    vector<int> ans;
    int path = k; 
    while (path != -1) {
        ans.push_back(path);
        path = rt[path];
    }

    for (int i=ans.size()-1; i>-1; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}