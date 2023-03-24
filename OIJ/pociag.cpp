#include <bits/stdc++.h>

using namespace std;

int wag[1000001], sur[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> wag[i];

	for (int i = 1; i <= n; i ++) {
		int a;
		cin >> a;

		sur[a] = i;
	}

	long long dis = 0, pos = 1;
	for (int i = n; i >= 1; i --) {
		if (pos > sur[wag[i]])
			dis += ((long long)sur[wag[i]] + n - pos);
		else
			dis += (long long)sur[wag[i]] - pos;
		pos = sur[wag[i]];
	}

	cout << (dis + n - 1) / n;
}
