#include <iostream>

using namespace std;

int n, m;
int arb[1000001], ban[1000001];

int arb_to_ban(int val) {
	int l = 1, r = m;

	while (l < r) {
		int sr = (l + r) / 2;

		if (ban[sr] < val)
			l = sr + 1;
		else
			r = sr;
	}
	return l;
}

int ban_to_arb(int val) {
	int l = 1, r = n;

	while (l < r) {
		int sr = (l + r) / 2;

		if (arb[sr] < val)
			l = sr + 1;
		else
			r = sr;
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> arb[i];
		arb[i] += arb[i - 1];
	}

	for (int i = 1; i <= m; i ++) {
		cin >> ban[i];
		ban[i] += ban[i - 1];
	}

	int q;
	cin >> q;

	while (q --) {
		int dzi, msc;
		char c;

		cin >> dzi >> msc >> c;

		int nr_dnia;

		if (c == 'A') {
			nr_dnia = arb[msc - 1] + dzi;

			cout << nr_dnia - ban[arb_to_ban(nr_dnia) - 1]
				<< ' ' << arb_to_ban(nr_dnia) << '\n';
		}
		else {
			nr_dnia = ban[msc - 1] + dzi;
			
			cout << nr_dnia - arb[ban_to_arb(nr_dnia) - 1]
				<< ' ' << ban_to_arb(nr_dnia) << '\n';
		}
	}
}