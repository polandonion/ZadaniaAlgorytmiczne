#include <bits/stdc++.h>

using namespace std;

short arr[101];

int main() {
    int n, m;
    cin >> n >> m;

    for (int y = 1; y <= m; y ++) {
        for (int x = 1; x <= n; x ++) {
            int a;
            cin >> a;

            arr[x] += a;
        }
    }
    for (int i = 1; i <= n; i ++)
        cout  << arr[i] << ' ';
}