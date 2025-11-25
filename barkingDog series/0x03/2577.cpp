#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 숫자 개수 배열
    short arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // 999^3 < 10억 10^10
    int multipled;
    short a, b, c, tmp;

    cin >> a;
    cin >> b;
    cin >> c;

    multipled = a * b * c;

    while (multipled > 0) {
        tmp = multipled % 10;
        arr[tmp]++;
        multipled /= 10;
    }

    for (short i=0; i<10; i++) {
        cout << arr[i] << "\n";
    }
}