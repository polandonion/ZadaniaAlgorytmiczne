#include <iostream>
#include <algorithm>

using namespace std;

struct Liczba {
	int war, idx;

	bool operator < (const Liczba &liczba) const {
		if (war == liczba.war)
			return (idx < liczba.idx);
		return (war < liczba.war);
	}
};

Liczba a[100001];
int n, q = 2, j = 1, b[100001];
int lew[100001], pra[100001];
int tree[300001];

void upd(int v) {
	v += q;
	while (v >= 1) {
		tree[v] ++;
		v = v >> 1;
	}
}

int sum(int l, int p) {
	l = l + q - 1;
	p += q + 1;

	int suma = 0;
	while (l / 2 != p / 2) {
		if (l % 2 == 0)
			suma += tree[l + 1];
		if (p % 2 == 1)
			suma += tree[p - 1];

		l /= 2;
		p /= 2;
	}
	return suma;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].war;
		a[i].idx = i;
	}

	sort(a + 1, a + n + 1);

	// SKALOWANIE
	b[a[1].idx] = j;
	for (int i = 2; i <= n; i ++) {
		if (a[i].war == a[i - 1].war)
			b[a[i].idx] = j;
		else
			b[a[i].idx] = ++j;
	}

	while (q < n)
		q = q << 1;
	q --;

	for (int i = 1; i <= n; i ++) {
		upd(b[i]);
		lew[i] = sum(1, b[i] - 1);
	}

	for (int i = 1; i <= q + j; i ++)
		tree[i] = 0;

	for (int i = n; i >= 1; i --) {
		upd(b[i]);
		pra[i] = sum(b[i] + 1, j);
	}

	long long wy = 0;
	for (int i = 1; i <= n; i ++)
		wy += (long long)lew[i] * pra[i];
	cout << wy;
}