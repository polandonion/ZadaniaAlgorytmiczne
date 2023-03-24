#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N = (1 << 17) - 1, n, m, x, y;
int a[524289];
string s;

void bld() {
	for (int i = N + 1; i <= N + n; i ++)
		cin >> a[i];
	
	for (int i = N; i >= 1; i --)
		a[i] = max(a[i * 2], a[i * 2 + 1]);
}

void upd(int X, int Y) {
	a[N + X] = Y;
	for (int i = (N + X) / 2; i >= 1; i /= 2)
		a[i] = max(a[i * 2], a[i * 2 + 1]);
}

int getMax(int X, int Y) {
	int maxi = -1e6;
	X += N; Y += N;
	while (X <= Y) {
		maxi = max(maxi, max(a[X], a[Y]));
		X = (X + 1) / 2;
		Y = (Y - 1) / 2;
	}
	return maxi;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bld();
	for (int i = 0; i < m; i ++) {
		cin >> s >> x >> y;
		if (s == "MAX") cout << getMax(x, y) << '\n';
		else upd(x, y);
	}
}
