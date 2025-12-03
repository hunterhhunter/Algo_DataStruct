#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <vector>
#include <algorithm>

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

        // 일반큐 생성
        deque<int> dq;

        for (string t : str_vector) {
            dq.push_back(stoi(t));
        }

        // 현재 true = 정배열, false = 역배열
        bool flag = true;
        bool flag2 = true;

        // 명령 실행
        // 정배열일때 앞에서빼기, 역배열일때 뒤에서빼기
        // 굳이 뒤집을 필요 X
        for (auto t : instruction) {
            if (t == 'R') {
                flag = !flag;
            } else {
                if (flag) {
                    if (!dq.empty()) {
                        dq.pop_front();
                    } else {
                        cout << "error" << "\n";
                        flag2 = false;
                        break;
                    }
                } else {
                    if (!dq.empty()) {
                        dq.pop_back();
                    } else {
                        cout << "error" << "\n";
                        flag2 = false;
                        break;
                    }
                }
            }
        }

        if (!flag2) {
            continue;
        } 

        if (!flag) {
            reverse(dq.begin(), dq.end());
        }

        cout << "[";
        for (int i=0; i<dq.size();i++) {
            cout << dq[i];
            if (i != dq.size()-1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}