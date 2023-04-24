#include <iostream>
#include <algorithm>

using namespace std;

int arr[5000009];

int binS(int l, int r, int s) {
	if(arr[0] >= s) return 0;
	if(arr[r] < s) return r + 1;
	int mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if(arr[mid] >= s) r = mid - 1;
		else l = mid;
	}
	return l + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, tmp = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		tmp = max(tmp, arr[i]);
		arr[i] = tmp;
	}
	for (int i = 0; i < m; i ++) {
		cin >> tmp;
		cout << binS(0, n - 1, tmp) << ' ';
	}
}