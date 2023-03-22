#include <iostream>

using namespace std;

bool pnp(int n, bool p, bool np) {
	if(n) {
		if((n % 10) % 2 == 0) p = 1;
		else np = 1;
		return pnp (n / 10, p, np);
	}
	if(p == 1 and np == 1) return 1;
	else return 0;
}

int main() {
	int n;
	cin >> n;
	cout << (pnp(n, 0, 0) == 1 ? "TAK" : "NIE"); 
}
