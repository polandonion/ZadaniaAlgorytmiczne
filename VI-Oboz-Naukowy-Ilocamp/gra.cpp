#include <bits/stdc++.h>

using namespace std;

short ARR[1000001];
long long DP[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> ARR[i];

	const int INF = -(1e9 + 1);
	for (int i = 1; i <= n; i ++)
		DP[i] = INF;

	DP[1] = ARR[1];
	
	for (int i = 2; i <= n; i ++)
		for (int j = 1; j <= 6; j ++)
			DP[i] = max(DP[i], DP[max(i - j, 1)] + ARR[i]);

	cout << DP[n];

}