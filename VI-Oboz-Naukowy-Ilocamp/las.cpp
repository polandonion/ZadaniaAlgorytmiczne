#include <bits/stdc++.h>

#define a first
#define b second

using namespace std;

int N, P, ODW, GRAF[1001][1001];
bool VIS[1001][1001];
vector <int> V;
queue <pair <int, int>> Q;

void bfs(int x, int y, int k) {
	ODW = 1;
	Q.push({x, y});
	VIS[x][y] = 1;

	while (!Q.empty()) {
		x = Q.front().a;
		y = Q.front().b;
		Q.pop();

		if (x > 1 and GRAF[x - 1][y] <= k and !VIS[x - 1][y])
			Q.push({x - 1, y}), ODW ++, VIS[x - 1][y] = 1;

		if (x < N and GRAF[x + 1][y] <= k and !VIS[x + 1][y])
			Q.push({x + 1, y}), ODW ++, VIS[x + 1][y] = 1;

		if (y > 1 and GRAF[x][y - 1] <= k and !VIS[x][y - 1])
			Q.push({x, y - 1}), ODW ++, VIS[x][y - 1] = 1;

		if (y < N and GRAF[x][y + 1] <= k and !VIS[x][y + 1])
			Q.push({x, y + 1}), ODW ++, VIS[x][y + 1] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> P;

	for (int y = 1; y <= N; y ++) {
		for (int x = 1; x <= N; x ++) {
			cin >> GRAF[x][y];
			V.push_back(GRAF[x][y]);
		}
	}
		
	sort(V.begin(), V.end());

	int l = 0, r = V.size() - 1, sr, mx;
	while (l < r) {
		mx = 0;
		sr = (l + r) / 2;

		for (int y = 1; y <= N; y ++) {
			for (int x = 1; x <= N; x ++) {
				if (!VIS[x][y] and GRAF[x][y] <= V[sr])
					bfs(x, y, V[sr]);
				mx = max(mx, ODW);
			}
		}

		if (mx < P)
			l = sr + 1;
		else
			r = sr;

		for (int y = 1; y <= N; y ++)
			for (int x = 1; x <= N; x ++)
				VIS[x][y] = 0;
	}

	cout << V[l];
}