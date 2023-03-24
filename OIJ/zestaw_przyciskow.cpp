#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int maxNas, maxPop;
	maxPop = maxNas = 0;

	while (k --) {
		int a;
		cin >> a;

		if (a == n + 1) {
			maxPop = maxNas;
			continue;
		}

		if (arr[a] < maxPop)
			arr[a] = maxPop;
		arr[a] ++;

		maxNas = max(maxNas, arr[a]);
	}

	for (int i = 1; i <= n; i ++) {
		if (arr[i] < maxPop)
			arr[i] = maxPop;
		cout << arr[i] << ' ';
	}
}
