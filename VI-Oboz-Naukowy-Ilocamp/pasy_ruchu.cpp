#include <bits/stdc++.h>

using namespace std;

int X, Y, DP[1001][1001]; 
bool GRAF[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> Y >> X;

	for (int y = 1; y <= Y; y ++)
		for (int x = 1; x <= X; x ++)
			cin >> GRAF[x][y];

	const unsigned int INF = 1e6 + 1;
	for (int y = 1; y <= Y; y ++)
		for (int x = 1; x <= X; x ++)
			DP[x][y] = INF;

	for (int x = 1; x <= X; x ++) {
		for (int y = 1; y <= Y; y ++) {
			if (!GRAF[x][y] and !GRAF[x - 1][y])
				DP[x][y] = DP[x - 1][y];
		}

		for (int y = 1; y <= Y; y ++) {
			if (!GRAF[x][y]) {
				if (y > 1)
					DP[x][y] = min(DP[x][y], DP[x][y - 1] + 1);

				DP[x][y] = min(DP[x][y], DP[x - 1][y]);

				if (y < Y)
					DP[x][y] = min(DP[x][y], DP[x][y + 1] + 1);
			}
		}

		for (int y = Y; y >= 1; y --) {
			if (!GRAF[x][y]) {
				if (y > 1)
					DP[x][y] = min(DP[x][y], DP[x][y - 1] + 1);

				DP[x][y] = min(DP[x][y], DP[x - 1][y]);

				if (y < Y)
					DP[x][y] = min(DP[x][y], DP[x][y + 1] + 1);
			}
		}
	}

	int mn = DP[X][1];
	for (int y = 2; y <= Y; y ++)
		mn = min(mn, DP[X][y]);
	
	if (mn != INF)
		cout << mn;
	else
		cout << "NIE";
}