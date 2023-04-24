#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long sr = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> arr[i];
		sr += (long long)arr[i];
	}

	sr /= n;

	int ile = 0;
	for (int i = 1; i <= n; i ++) {
		if (arr[i] > sr) {
			ile ++;
			arr[i + 1] += (arr[i] - sr);
		}
		else if (arr[i] < sr) {
			ile ++;
			arr[i + 1] -= (sr - arr[i]);
		}
	}

	cout << ile;
}