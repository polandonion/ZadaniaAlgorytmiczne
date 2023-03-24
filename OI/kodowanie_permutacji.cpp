#include <iostream>
#include <algorithm>
#define N 100000

using namespace std;

int n, zak[N + 1], odk[N + 1];
int tree[3 * N], q;

void build_tree() {
	for (int i = q + 1; i <= q + n; i ++)
		tree[i] ++;

	for (int i = q; i >= 1; i --)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void upd(int v) {
	while (v >= 1) {
		tree[v] --;
		v >>= 1;
	}
}

int kthElem(int k) {
	int v = 1;
	while (v <= q) {
		if (tree[v * 2 + 1] < k) {
			k -= tree[v * 2 + 1];
			v <<= 1;
		}
		else
			v = (v << 1) + 1;
	}

	upd(v);
	return v - q;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> zak[i];

		if (zak[i] >= i) {
			cout << "NIE";
			return 0;
		}
	}

	q = 1;
	while (q < n)
		q <<= 1;
	q --;

	build_tree();

	for (int i = n; i >= 1; i --)
		odk[i] = kthElem(zak[i] + 1);

	for (int i = 1; i <= n; i ++)
		cout << odk[i] << '\n';
}
