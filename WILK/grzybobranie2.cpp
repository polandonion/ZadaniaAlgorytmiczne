#include <iostream>
#include <algorithm>

using namespace std;

long long tab[1000009];
int n, q, x; 
long long y;

long long iloscGrzybow(int poz, int r) {
	return (tab[min(poz + r, n)] - tab[max(poz - r - 1, 0)]);
}

int lowerBound(int l, int p) {
	if(l == p) return l;
	int sr = (l + p) / 2;
	long long wynik = iloscGrzybow(x, sr);
	if(wynik >= y) return lowerBound(l, sr);
	else return lowerBound(sr + 1, p);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	tab[0] = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(i == 1) tab[i] = x;
		else tab[i] = x + tab[i - 1];
	}
	for(int i = 0; i < q; i++) {
		cin >> x >> y;
		if(tab[n] < y) cout << "NIEMOZLIWE\n";
		else if(iloscGrzybow(x, 0) >= y) cout << 0 << endl;
		else cout << lowerBound(0, 1000000) << endl;
	}
}
