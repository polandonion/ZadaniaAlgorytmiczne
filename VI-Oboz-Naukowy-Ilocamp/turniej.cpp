#include <bits/stdc++.h>

using namespace std;

int wy1(int a, int b) {
	int gru, poz;

	while (a >= b) {
		gru = a / b;
		poz = a % b;

		a = gru * (b - 1) + poz;
	}

	return a;
}

int wy2(int a, int b) {
	return min(a, b - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;

	while (q --) {
		int a, b;
		cin >> a >> b;

		//cout << wy1(a, b) << '\n';
		cout << wy2(a, b) << '\n';
	}
}