#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int room, tmp;
    short arr[10] = {0, };
    short ans = 0;

    cin >> room;

    while (room > 0) {
        tmp = room % 10;
        if (tmp == 6 || tmp == 9) {
            arr[6]++;
        } else {
            arr[tmp]++;
        }
        room /= 10;
    }

    if (arr[6] % 2 == 0) {
        arr[6] = arr[6] / 2;
    } else {
        arr[6] = arr[6] / 2 + 1;
    }

    for (short i=0; i < 10; i++) {
        ans = max(ans, arr[i]);
    }

    cout << ans << "\n";
}