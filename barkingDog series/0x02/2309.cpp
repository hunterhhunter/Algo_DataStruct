#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    short arr[9] = {};

    int sum = 0;
    for (int i=0; i<9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i=0; i < 9; i++) {
        for (int j = i+1; j<9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                int a = arr[i];
                int b = arr[j];
                sort(arr, arr+9);
                for (int l = 0; l<9; l++) {
                    if (arr[l] == a || arr[l] == b) {
                        continue;
                    } else {
                        cout << arr[l] << "\n";
                    }
                }
                return 0;
            }
        }
    }
}