#include <bits/stdc++.h>

using namespace std;

int arr[2000002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	n *= 2;

	for (int i = 1; i <= n; i ++)
		cin >> arr[i];
	arr[n + 1] = -1;

	sort(arr + 1, arr + n + 1);

	if (arr[1] == arr[n]) {
		cout << arr[1] << ' ' << arr[1];
		return 0;
	}

	int cb = 1, npa = 0, p, k;
	for (int i = 2; i <= n + 1; i ++) {
		if (arr[i] == arr[i - 1])
			cb ++;
		else {
			if (cb % 2 == 1) {
				npa ++;

				if (npa == 1)
					p = arr[i - 1];
				k = arr[i - 1];
			}

			cb = 1;
		}
	}

	if (npa == 2)
		cout << p << ' ' << k;
	else
		cout << "NIE";
}