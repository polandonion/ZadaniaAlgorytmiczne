#include <bits/stdc++.h>

using namespace std;

int arr[300001];

int uppBou(int l, int p, int x) {
	if (l == p)
		return l;

	int mid;
	while (l < p) {
		mid = (l + p + 1) / 2;
		if (arr[mid] >= x)
			l = mid;
		else p = mid - 1;
	}
	return p;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k, q;
	cin >> n >> m;
	if (m > n) {
		cout << 0;
		return 0;
	}

	cin >> arr[1];
	for (int i = 2; i <= n; i ++) {
		cin >> arr[i];
		arr[i] = min(arr[i], arr[i - 1]);
	}

	q = n + 1;
	while (m --) {
		cin >> k;
		if (k > arr[1] or q == 0)
			q = 0;
		else
			q = uppBou(1, q - 1, k);
	}
	cout << q;
}
