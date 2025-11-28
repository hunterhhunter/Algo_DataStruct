// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     for (int i=0; i<n; i++) {
//         stack<char> stk;

//         //bool flag = true;
//         string a;
//         cin >> a;

//         int j;
//         for (j=0; j<a.length(); j++) {
//             if (a[j] == '(') {
//                 stk.push(a[j]);
//             } else {
//                 if (stk.empty()) {
//                     //flag = false;
//                     break;
//                 } else {
//                     stk.pop();
//                 }
//             }
//         }

//         if (!stk.empty() || j < a.length()) {
//             cout << "NO" << "\n";
//         } else {
//             cout << "YES" << "\n";
//         }
//     }
// }

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int cnt1 = 0;

        //bool flag = true;
        string a;
        cin >> a;

        int j;
        for (j=0; j<a.length(); j++) {
            if (a[j] == '(') {
                cnt1++;
            } else {
                if (cnt1 <= 0) {
                    break;
                } else {
                    cnt1--;
                }
            }
        }

        if (cnt1 != 0 || j < a.length()) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}