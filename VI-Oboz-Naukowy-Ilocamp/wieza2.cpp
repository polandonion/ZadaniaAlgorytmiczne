#include <iostream>
#include <algorithm>

using namespace std;

int a[5000001];

int bs(int l, int r, int x) {
	if (x <= a[1] or l > r) return 0;
	int mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (a[mid] >= x) r = mid - 1;
		else l = mid;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n, m, maxi = 0, x, r;
	cin >> n >> m;
	r = n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
		a[i] = maxi;
	}
	while (m --) {
		cin >> x;
		r = bs(1, r, x);
		cout << max(r, 0) << ' ';
		r --;
	}
}