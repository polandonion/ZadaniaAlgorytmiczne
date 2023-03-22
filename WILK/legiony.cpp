#include <iostream>

using namespace std;

long long w = 1, q = 1e9 + 7;

long long pot(int n, int k) {
	if(k == 0) return 1;
	if(k == 1) return n;
	if(k % 2 == 0){
		w = pot(n, k / 2) % q;
		w = (w * w) % q;
	}
	else{
		w = pot(n, k / 2) % q;
		w = ((w * w) % q * n) % q;
	}
	return w;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t, r, k, b, m;
	long long wy;
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> r >> k >> b >> m;
		wy = (pot(r, k) % q * pot(b, m) % q) % q;
		cout << wy << endl;
	}
}
