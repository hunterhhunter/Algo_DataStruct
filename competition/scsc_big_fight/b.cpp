#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, idx=0;
    cin >> n >> m;

    vector<int> ref(n, 0);

    while (n--) {
        cin >> ref[idx];
        idx++;
    }

    while (m--) {
        int l, h;
        cin >> l >>h;

        auto mx = max_element(ref.begin(), ref.end());

        if (*mx == ref[h-1]) {
            continue;
        } else {
            ref[l-1]--;
        }
    }

    for (auto t: ref) {
        cout << t << " ";
    }

    return 0;
}