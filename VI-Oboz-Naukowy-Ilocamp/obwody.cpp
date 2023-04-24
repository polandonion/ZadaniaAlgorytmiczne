#include <iostream>
#include <algorithm>

using namespace std;

signed int a[500000];

int main() {
	int n, x, y, k = 0, i = 0, j; cin >> n;
	long long suBa = 0, suDr = 0;
	while (n --) {
		cin >> x >> y;
		if (x >= y) {
			suDr += x;
			suBa += y;
			k ++;
		}
		else a[i ++] = x - y;
	}
	sort(a, a + i, greater<long long>());
	j = 0;
	while (suDr >= suBa and suDr + a[j] >= suBa and j < i) {
		suDr += a[j ++];
		k ++;
	}
	cout << k;
}