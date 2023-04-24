#include <iostream>

using namespace std;

long long nwd(long long a, long long b) {
	if (b == 0) return a;
	return nwd(b, a % b);
}

long long nww(long long a, long long b) {
	long long wy = a * b / nwd(a, b);
	return wy;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	long long q, n, k;
	cin >> q;
	while (q --) {
		cin >> n >> k;
		cout << nww(n, k) / k << '\n';
	}
}