#include <iostream>
#include <string>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    int ans = 0, star = 0;

    for (int i=0; i<12; i++) {
        if (inp[i] == '*') {
            if (i % 2 == 1) {
                star = 3;
            } else {
                star = 1;
            }
        } else {
            if (i % 2 == 0) {
                ans += (int)(inp[i]-'0');
            } else {
                ans += ((int)(inp[i]-'0') * 3);
            }
        }
    }
    int m = (int)(inp[inp.length()-1]-'0');

    for (int i=0; i<10; i++) {
        if (m == (10 - ((ans+i*star)%10))%10) {
            cout << i;
            break;
        }
    }

    return 0;
}