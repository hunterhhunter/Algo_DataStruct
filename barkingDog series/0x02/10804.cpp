#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
    int times = (b-a+1)/2;
    while (times > 0) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        a += 1;
        b -= 1;
        times -= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];
    for (int i=1;i<21;i++) {
        arr[i] = i;
    }

    for (int i=0;i<10;i++) {
        int a, b;
        cin >> a >> b;

        swap(arr, a, b);
    }

    for (int i=1; i<21;i++) {
        cout << arr[i] << " ";
    }
}