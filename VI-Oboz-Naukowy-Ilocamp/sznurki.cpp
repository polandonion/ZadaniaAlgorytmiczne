#include <iostream>

using namespace std;

long long arr[1000009];
long long pom = 0;
int n, w, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> w >> x;
	arr[0] = x;
	for (int i = 1; i < n; i ++) {
		cin >> x;
		arr[i] = arr[i - 1] + x;
	} x = 0;
	for(int i = 0; i < n; i ++) {
		if (arr[i] - pom >= w) {
			pom = arr[i];
			x ++;
		}
	}
	cout << x;
}