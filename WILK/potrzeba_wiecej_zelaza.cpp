#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long zel, mie;
	cin >> zel >> mie;

	mie <<= 1; // to samo co mie *= 2

	cout << min(zel, mie / 3);
}