#include <bits/stdc++.h>

using namespace std;

short arr[100001];
long long dp[100001];

long long ans(int n) {
    dp[1] = arr[1];
    dp[2] = arr[2];
    for (int i = 3; i <= n; i ++)
        dp[i] = arr[i] + min(dp[i - 1], dp[i - 2]);
    return min(dp[n], dp[n - 1]);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++)
        cin >> arr[i];

    cout << ans(n);
}
