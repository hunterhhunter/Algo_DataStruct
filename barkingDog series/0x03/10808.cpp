#include <iostream>
#include <string>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    int arr[26] = {0, };

    for (int i=0; i<inp.length(); i++) {
        arr[(int)inp[i]-97]++;
    }

    for (int i=0; i<26; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}