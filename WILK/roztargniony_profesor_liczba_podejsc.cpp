#include <bits/stdc++.h>

using namespace std;

long long dp[91];

long long ans(int n) {
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i ++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << ans(n);
}
