#include <string>
#include <iostream>

using namespace std;

int main() {
    string inp;
    cin >> inp;

    if (inp[0] == 'F') {
        cout << "Foundation";
    } else if (inp[0] == 'C') {
        cout << "Claves";
    } else if (inp[0] == 'V') {
        cout << "Veritas";
    } else if (inp[0] == 'E') {
        cout << "Exploration";
    }
    return 0;
}