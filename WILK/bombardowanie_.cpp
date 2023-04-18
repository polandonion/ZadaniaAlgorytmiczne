#include <iostream>
#include <cmath>

using namespace std;

struct Pkt {
	long long x, y;
};

Pkt a[100000];

long long ilo(Pkt P, Pkt A, Pkt B) {
	return ((A.x-P.x)*(B.y-P.y) -
			(B.x-P.x)*(A.y-P.y));
}

bool wew(Pkt P, Pkt A, Pkt B, Pkt C) {
	return (abs(ilo(A, B, C)) ==
			abs(ilo(A, B, P)) +
			abs(ilo(B, C, P)) +
			abs(ilo(A, C, P)));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i ++)
		cin >> a[i].x >> a[i].y;

	int ile = 0;
	while (m --) {
		Pkt P;
		cin >> P.x >> P.y;

		int l = 1, r = n - 1;
		while (l + 1 < r) {
			int sr = (l + r) / 2;

			if (ilo(a[0], a[sr], P) > 0)
				l = sr;
			else
				r = sr;
		}

		ile += wew(P, a[0], a[l], a[r]);
	}

	cout << ile;
}