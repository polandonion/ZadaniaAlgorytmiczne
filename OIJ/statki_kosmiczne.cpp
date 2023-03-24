#include <iostream>
#include <algorithm>

using namespace std;

long long A[1001], B[1001], C[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	int n, m, o;

	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> A[i];

	cin >> m;
	for (int i = 1; i <= m; i ++)
		cin >> B[i];

	cin >> o;
	for (int i = 1; i <= o; i ++)
		cin >> C[i];

	sort(A + 1, A + n + 1);
	sort(B + 1, B + m + 1);
	sort(C + 1, C + o + 1);

	long long pol = (a * A[n] + b * B[m] + c * C[o]) / 2;
	long long wyn = 0;

	for (int i = o; i >= 1; i --) {
		long long l = 1, r = n;
		for (int j = m; j >= 1; j --) {
			long long tmp = c * C[i] + b * B[j];

			while (l <= r and tmp + a * A[l] <= pol)
				l ++;

			if (l <= r)
				wyn += r - l + 1;
		}
	}
	cout << wyn;
}
