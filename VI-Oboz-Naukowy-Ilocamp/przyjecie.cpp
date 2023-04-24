#include <bits/stdc++.h>

using namespace std;

int arr[1000001], n;
bool exc[100001];

void exclude() {
	exc[1] = 1;

	for (int i = 1; i <= n; i ++) {
		int x = arr[i];
		
		if (!exc[x]) {
			exc[x] = 1;

			for (int j = 2; j * j <= x; j ++) {
				if (x % j == 0) {
					if (!exc[j])
						exc[j] = 1;
					if (!exc[x / j])
						exc[x / j] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> arr[i];

	exclude();

	for (int i = 2; i <= 1e5 + 1; i ++) {
		if (!exc[i]) {
			cout << i;
			break;
		}
	}
}