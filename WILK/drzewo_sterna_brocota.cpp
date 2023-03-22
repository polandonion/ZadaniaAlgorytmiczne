#include <iostream>

using namespace std;

short tab[1100000];

void budTab(int l, int p) {
	if(p - l < 2) return;
	int sr = (l + p) / 2;
	tab[sr] = tab[l] + tab[p];
	budTab(l, sr);
	budTab(sr, p);
}

int main() {
	int n;
	cin >> n;
	int roz = (1 << n) + 1;
	tab[1] = 0;
	tab[roz] = 1;
	budTab(1, roz);
	for(int i = 1; i <= roz; i ++) {
		cout << tab[i] << '/' << tab[roz - i + 1] << ' ';
	}
}
