#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> map(200000, -1);

    queue<int> q;
    map[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int current = q.front();

        q.pop();

        for (int nxt : {current+1, current-1, current*2}) {
            if (nxt < 0 || nxt > 100001) {continue;}
            if (map[nxt] != -1) {continue;}
            map[nxt] = map[current]+1;
            q.push(nxt);
        }
    }
    
    cout << map[k];

    return 0;
}