#include <iostream>

using namespace std;

int tab[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int a, b, c, d, ile = 0;
	cin >> a >> b >> c >> d;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> tab[i][j];

	for (int i = 2; i <= n; i ++)
		for (int j = 2; j <= m; j ++)
			if (tab[i][j] * tab[i][j - 1] * tab[i - 1][j] * tab[i - 1][j - 1] == a * b * c * d)
				ile ++;

	cout << ile;
}
