#include <bits/stdc++.h>

using namespace std;

bool arr[1001][1001];
int dp[1002][1002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int y = 1; y <= n; y ++)
		for (int x = 1; x <= n; x ++)
			cin >> arr[x][y];

	int q;
	cin >> q;

	while (q --) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		dp[x1][y1] ++;
		dp[x2 + 1][y2 + 1] ++;
		dp[x1][y2 + 1] --;
		dp[x2 + 1][y1] --;
	}

	for (int y = 1; y <= n; y ++) {
		int su = 0;
		for (int x = 1; x <= n; x ++) {
			su += dp[x][y];
			dp[x][y] = su;
		}
	}
	for (int x = 1; x <= n; x ++) {
		int su = 0;
		for (int y = 1; y <= n; y ++) {
			su += dp[x][y];
			dp[x][y] = su;
		}
	}

	for (int y = 1; y <= n; y ++) {
		for (int x = 1; x <= n; x ++)
			cout << (arr[x][y] + dp[x][y] % 2) % 2 << ' ';
		cout << '\n';
	}
}