#include <bits/stdc++.h>

using namespace std;

vector <int> vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while (n --) {
        int x;
        cin >> x;

        vec.push_back(x);
    }

    int mxAkt = 0, mx = 0, mxRoz = 0;
    for (int i = 1; i < vec.size(); i ++) {
        if (vec[i] >= vec[i - 1]) {
            mxAkt ++;
            mx = max(mx, mxAkt);
            mxRoz = max(mxRoz, vec[i] - vec[i - mxAkt]);
        }
        else
            mxAkt = 0;
    }

    cout << mxRoz;
}
