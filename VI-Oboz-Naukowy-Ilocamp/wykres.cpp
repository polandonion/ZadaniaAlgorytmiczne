#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> arr[i];

	bool zer = 0, jed = 0, dwa = 0;
	int mx = 0;
	for (int i = 1; i <= n; i ++) {
		if (arr[i] == 0) {
			zer = 1, jed = 0, dwa = 0;
			mx = max(mx, 1);
			
		}
		else if (arr[i] == 1) {
			jed = 1, dwa = 0;
			mx = max(mx, 1);
			
			if (zer == 1)
				mx = max(mx, 2);
		}
		else {
			dwa = 1;
			mx = max(mx, 1);

			if (jed == 1) {
				mx = max(mx, 2);

				if (zer == 1)
					mx = max(mx, 3);
			}
			if (zer == 1)
				mx = max(mx, 2);
		}
	}

	cout << mx;
}