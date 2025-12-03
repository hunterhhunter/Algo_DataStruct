#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;

    int front = 1, back = n+1;
    int arr[2*n+1] = {0, };

    for (int i=0; i<=n; i++) {
        arr[i] = i;
    }

    // 리스트로 큐의 동작을 흉내내기
    while (back - front > 1) {
        front++;
        arr[back] = arr[front];
        front++;
        back++;
    }

    cout << arr[back-1] << "\n";
    return 0;
}