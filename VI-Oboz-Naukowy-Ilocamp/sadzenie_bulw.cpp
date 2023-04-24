#include <bits/stdc++.h>

using namespace std;

int ARR[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> ARR[i];

	sort(ARR + 1, ARR + n + 1);

	int m;
	cin >> m;

	unsigned long long wy = 0;
	for (int i = n; i >= 1; i --) {
		if (m == 0)
			break;

		wy += min(ARR[i], m) * min(ARR[i], m);
		m -= min(ARR[i], m);
	}

	cout << wy;
}