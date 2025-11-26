#include <iostream>

using namespace std;

int main() {
    int n, x, tmp;
    short arr[201] = {0, };

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> tmp;
        arr[tmp+100]++;
        //cout << arr[tmp+100];
    }

    cin >> x;


    cout << arr[x+100]<< "\n";

}