#include <bits/stdc++.h>

using namespace std;

int h[1000001], d[1000000];
long long p[1000001], k[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> h[i];

	for (int i = 1; i < n; i ++)
		cin >> d[i];

	for (int i = 1; i <= n; i ++) {
		p[i] = p[i - 1] + (long long)d[i - 1];
		k[i] = p[i] + (long long)h[i];
	}

	long long pop = 1, wyn = 2, nas;
	while (k[pop] <= p[n]) {
		long long j = nas = pop + 1;

		while (k[pop] > p[j]) {
			if (k[j] > k[nas])
				nas = j;
			j ++;
		}
		
		pop = nas;
		wyn ++;
	}

	cout << n - wyn;
}