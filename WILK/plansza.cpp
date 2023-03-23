#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	if (a % 2 == 0 and b % 2 == 0)
		cout << (a + b) / 2;
	else
		cout << (a + b) / 2 - 1;
}