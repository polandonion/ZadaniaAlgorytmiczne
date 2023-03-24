#include <iostream>

using namespace std;

long long tab[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> tab[i];
		tab[i] += tab[i - 1];
	}

	long long sum = 0;
	while (m --) {
		int a, b;
		cin >> a >> b;

		if (tab[b] - tab[a - 1] > 0)
			sum += tab[b] - tab[a - 1];
	}
	cout << sum;
}
