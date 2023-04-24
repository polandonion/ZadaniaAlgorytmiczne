#include <bits/stdc++.h>

using namespace std;

long long slupy[1048576], pietra[524288];
long long dp[1000001];
int n, m, k, ileSlupow, ilePieter;

void buildTree() {
	ileSlupow = (1 << (n + 1)) - 1;
	ilePieter = (1 << n) - 1;

	for (int i = 2; i <= ileSlupow; i ++)
		cin >> slupy[i];

	for (int i = ileSlupow / 2; i >= 1; i --) {
		if (i * 2 > ilePieter)
			pietra[i] = min(slupy[i * 2], slupy[i * 2 + 1]) * 2;
		else
			pietra[i] = min(slupy[i * 2], min(slupy[i * 2 + 1], min(pietra[i * 2], pietra[i * 2 + 1]))) * 2;
	}
}

void update(int &a, int &b, int &c) {
	int pos = (1 << a) + b - 1;
	slupy[pos] = c;

	for (int i = pos / 2; i >= 1; i /= 2) {
		if (i * 2 > ilePieter)
			pietra[i] = min(slupy[i * 2], slupy[i * 2 + 1]) * 2;
		else
			pietra[i] = min(slupy[i * 2], min(slupy[i * 2 + 1], min(pietra[i * 2], pietra[i * 2 + 1]))) * 2;
	}
}

long long bs(long long x) {
	if (dp[1] > x)
		return 0;

	int l = 1, r = m;
	while (l < r) {
		int sr = (l + r + 1) / 2;

		if (dp[sr] > x)
			r = sr - 1;
		else
			l = sr;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	buildTree();

	for (int i = 1; i <= m; i ++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	cout << bs(pietra[1]) << '\n';
	while (k --) {
		int a, b, c;
		cin >> a >> b >> c;
		update(a, b, c);

		cout << bs(pietra[1]) << '\n';
	}
}