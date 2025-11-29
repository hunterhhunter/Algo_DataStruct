#include <iostream>
#include <string>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    int ans = 0, star = 0;

    for (int i=0; i<inp.length(); i++) {
        if (inp[i] == '*') {
            if (i % 2 == 0) {
                star = 3;
            } else {
                star = 1;
            }
        } else {
            if (i % 2 == 0) {
                ans += ((int)inp[i]-48) % 10;
            } else {
                ans += (((int)inp[i]-48) * 3)%10;
            }
        }
    }

    cout << 10 - (ans % 10) - (int)inp[inp.length()-1];
}