#include <iostream>
#include <algorithm>

using namespace std;

int n, m, q;

pair <long long, int> arr[1100000];

void buildArr() {
	q = (1 << 19) - 1;
	for (int i = q + 1; i <= q + n; i ++) {
		cin >> arr[i].first;
		arr[i].second = i - q;
	}
	for (int i = q; i >= 1; i --)
		arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
}

void update(int a, int b) {
	arr[a + q].first += b;
	for (int i = (a + q) / 2; i > 1; i /= 2)
		arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
}

int maxAB(int a, int b) {
	a += q; b += q;
	pair <long long, int> maxPr = {0, 0};
	while (a <= b) {
		maxPr = max(maxPr, max(arr[a], arr[b]));
		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return maxPr.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, k;
	cin >> n >> m;
	buildArr();
	while (m --) {
		cin >> k;
		while (k --) {
			cin >> a >> b;
			update(a, b);
		}
		cin >> a >> b;
		cout << maxAB(a, b) << '\n';
	}
}
