#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, h;
	cin >> n >> h;

	int wynik = 0;
	for (int i = 0; i <= n; i ++) {
		int x;
		cin >> x;

		if (x <= h)
			wynik ++;
		else
			wynik += 2;
	}
	cout << wynik;
}
