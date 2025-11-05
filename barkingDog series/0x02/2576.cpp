#include <iostream>
#include <climits>
using namespace std;

int main() {
    int mi = INT32_MAX;
    int sum = 0;

    for (int i = 0; i< 7; i++) {
        int tmp;
        cin >> tmp;

        if (tmp % 2 == 1) {
            sum += tmp;
            if (tmp < mi) {
                mi = tmp;
            }
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << sum << endl;
        cout << mi << endl;
    }

    return 0;
}