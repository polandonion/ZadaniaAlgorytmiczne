#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x[1000000], y[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++)
        cin >> x[i] >> y[i];

    sort(x, x + n);
    sort(y, y + n);

    int hot_x = x[n / 2];
    int hot_y = y[n / 2];

    long long sum = 0;
    for (int i = 0; i < n; i ++)
        sum += 2LL * ((long long)abs(hot_x - x[i]) + (long long)abs(hot_y - y[i]));
    cout << sum;
}