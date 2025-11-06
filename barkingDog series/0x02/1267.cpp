#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int minsik = 0;
    int youngsik = 0;
    for (int i=0;i<n;i++) {
        int alpha;
        cin >> alpha;
        youngsik += 10 * (alpha / 30 + 1);
        minsik += 15 * (alpha / 60 + 1);
    }

    if (minsik < youngsik) {
        cout << "M " << minsik << "\n";
    } else if (youngsik < minsik) {
        cout << "Y " << youngsik << "\n";
    } else {
        cout << "Y M " << youngsik << "\n";
    }

    return 0;
}