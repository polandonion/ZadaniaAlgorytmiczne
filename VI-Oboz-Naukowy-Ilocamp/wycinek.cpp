#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

long long dp[1000001];
vector <pair <long long, int>> v;

int pos(long long a) {
	int l = 0, r = v.size() - 1, sr;

	while (l < r) {
		sr = (l + r) / 2;

		if (v[sr].x < a)
			l = sr + 1;
		else
			r = sr;
	}

	return (v[l].x == a ? v[l].y : 1000000);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, s;
	cin >> n >> s;

	for (int i = 1; i <= n; i ++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	v.push_back({0, 0});
	for (int i = 1; i <= n; i ++)
		v.push_back({dp[i], i});

	sort(v.begin(), v.end());

	int mx = 0;
	for (int i = 1; i <= n; i ++)
		mx = max(mx, i - pos(dp[i] - s));
	
	if (mx > 0)
		cout << mx;
	else
		cout << "BRAK";
}