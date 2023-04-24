#include <iostream>

using namespace std;

int a[4000009];

int main() {
	ios_base::sync_with_stdio(0);
	int n, m, p = 1, q; cin >> n >> m;
	q = n;
	string s; cin >> s;
	for (int i = 1; i <= n; i ++) a[i] = i;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'A') {
			a[q + 1] = a[p];
			a[p] = 0;
			p ++; q ++;
		}
		else {
			a[q + 1] = a[p + 1];
			a[p + 1] = a[p];
			a[p] = 0;
			p ++; q ++;
		}
	}
	cout << a[p];
}