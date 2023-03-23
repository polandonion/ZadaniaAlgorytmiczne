#include <iostream>
#include <algorithm>

using namespace std;

int tree[520000];

void build(int &n, int &q) {
	for (int i = q + 1; i <= q + n; i ++)
		cin >> tree[i];

	for (int i = q; i >= 1; i --)
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int get_max(int &a, int &b, int &q) {
	int maxi = -1;
	a += q;
	b += q;

	while (a <= b) {
		maxi = max(maxi, max(tree[a], tree[b]));

		a = (a + 1) >> 1;
		b = (b - 1) >> 1;
	}

	return maxi;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int q = 1;
	while (q < n)
		q <<= 1;
	q --;

	build(n, q);

	while (m --) {
		int a, b;
		cin >> a >> b;

		cout << get_max(a, b, q) << ' ';
	}
}