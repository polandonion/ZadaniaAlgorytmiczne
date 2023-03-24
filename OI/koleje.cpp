#include <iostream>
#include <algorithm>

using namespace std;

int tree[150000], lazy[150000];
int p, k, q;

void push(int v, int l, int p) {
	tree[l] += lazy[v];
	tree[p] += lazy[v];

	lazy[l] += lazy[v];
	lazy[p] += lazy[v];

	lazy[v] = 0;
}

void add(int v, int a, int b, int val) {	
	if (k < a or b < p)
		return;
	else if (p <= a and b <= k) {
		tree[v] += val;
		lazy[v] += val;
	}
	else {
		int l = v * 2, p = v * 2 + 1, mid = (a + b) / 2;

		push(v, l, p);

		add(l, a, mid, val);
		add(p, mid + 1, b, val);
		
		tree[v] = max(tree[l], tree[p]);
	}
}

int getMax(int v, int a, int b) {
	if (k < a or b < p)
		return 0;
	else if (p <= a and b <= k)
		return tree[v];
	else {
		int l = v * 2, p = v * 2 + 1, mid = (a + b) / 2;

		push(v, l, p);

		return max(getMax(l, a, mid), getMax(p, mid + 1, b));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, o;
	cin >> n >> m >> o;

	q = 1;
	while (q < n)
		q *= 2;
	q --;

	while (o --) {
		int a, b, c;
		cin >> a >> b >> c;

		p = q + a, k = q + b - 1;
		if (getMax(1, q + 1, q + n) + c <= m) {
			cout << "T\n";
			add(1, q + 1, q + n, c);
		}
		else
			cout << "N\n";
	}
}
