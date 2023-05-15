#include <iostream>

using namespace std;

int arr[1000000], n, k;

bool da_sie(int x) {
	int p = 0, q = 0, ile = 1;

	while (q < n) {
		while (q < n and arr[q] - arr[p] < x)
			q ++;

		if (q < n) {
			p = q;
			ile ++;

			if (ile == k)
				return 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i ++)
		cin >> arr[i];

	int l = 1, r = arr[n - 1] - arr[0];
	while (l < r) {
		int sr = (l + r + 1) / 2;

		if (da_sie(sr))
			l = sr;
		else
			r = sr - 1;
	}
	cout << l;
}