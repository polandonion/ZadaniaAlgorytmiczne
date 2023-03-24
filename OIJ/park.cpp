#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int maxNaLewo[1000001], maxNaPrawo[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> arr[i];

	int mx = arr[1];
	for (int i = 1; i <= n; i ++) {
		mx = max(mx, arr[i]);
		maxNaLewo[i] = mx;
	}

	mx = arr[n];
	for (int i = n; i >= 1; i --) {
		mx = max(mx, arr[i]);
		maxNaPrawo[i] = mx;
	}

	for (int i = 1; i <= n; i ++)
		cout << maxNaLewo[i] << ' ' << maxNaPrawo[i] << '\n';
}
