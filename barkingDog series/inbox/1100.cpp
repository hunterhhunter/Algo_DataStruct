#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int ans = 0;
    for (int i=0; i<8; i++) {
        string inp;
        cin >> inp;

        for (int j=0; j<8; j++) {
            if (inp[j] == 'F') {
                if (i % 2 == 0 && j % 2 == 0) {
                    ans++;
                }
                if (i % 2 == 1 && j % 2 == 1) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}