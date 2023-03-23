#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q;
	cin >> q;

	while (q --) {
		long long a, b;
		cin >> a >> b;

		while (a % 2 == 0 or a % 3 == 0) {
			if (a % 2 == 0)
				a >>= 1;
			else
				a /= 3;
		}
		while (b % 2 == 0 or b % 3 == 0) {
			if (b % 2 == 0)
				b >>= 1;
			else
				b /= 3;
		}

		if (a == b)
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}