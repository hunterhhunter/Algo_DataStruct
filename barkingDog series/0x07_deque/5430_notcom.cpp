#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        // 명령 입력
        string instruction;
        cin >> instruction;

        // 배열 수 입력
        int n;
        cin >> n;

        cin.ignore();

        // 배열 입력
        string arr;
        getline(cin, arr);
        // 배열 정제
        arr.erase(0, 1);
        arr.pop_back();
        // 배열 문자열 -> 벡터
        string buffer;
        istringstream ss(arr);
        vector<string> str_vector;
        while (getline(ss, buffer, ',')) {
            str_vector.push_back(buffer);
        }

        // 일반큐, 리버스큐 생성
        deque<int> dq;
        deque<int> r_dq;

        for (string t : str_vector) {
            dq.push_back(stoi(t));
            r_dq.push_front(stoi(t));
        }

        
    }
}