#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long sa = 0, sb = 0, sc = 0;
	for (int i = 0; i < n; i ++) {
		long long a, b, c;
		cin >> a >> b >> c;

		sa += a;
		sb += b;
		sc += c;
	}

	if (sa == sb and sb == sc)
		cout << "TAK";
	else
		cout << -sa << ' ' << -sb << ' ' << -sc;
}