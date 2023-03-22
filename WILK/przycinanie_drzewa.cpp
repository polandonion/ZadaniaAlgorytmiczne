#include <iostream>

using namespace std;

bool tab[10485777];
int roz;

int drz(int n) {
	if(n > roz or tab[n] == 1) return 0;
	return 1 + drz(n * 2) + drz(n * 2 + 1);
}

int main() {
	int n, q, x;
	cin >> n >> q;
	roz = (1 << n) - 1;
	for(int i = 0; i < q; i ++) {
		cin >> x;
		tab[x] = 1;
	}
	cout << drz(1);
}
