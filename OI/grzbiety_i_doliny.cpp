#include <bits/stdc++.h>

#define a first
#define b second

using namespace std;

int N, GRAF[1001][1001];
bool WAR, VIS[1001][1001];
queue <pair <int, int>> Q;

void bfsGrz(int x, int y, int k) {
	Q.push({x, y});
	VIS[x][y] = 1;

	while (!Q.empty()) {
		x = Q.front().a;
		y = Q.front().b;
		Q.pop();

		if (x > 1 and y > 1) {
			if (GRAF[x - 1][y - 1] == k and !VIS[x - 1][y - 1])
				Q.push({x - 1, y - 1}), VIS[x - 1][y - 1] = 1;
			if (GRAF[x - 1][y - 1] > k)
				WAR = 1;
		} if (y > 1) {
			if (GRAF[x][y - 1] == k and !VIS[x][y - 1])
				Q.push({x, y - 1}), VIS[x][y - 1] = 1;
			if (GRAF[x][y - 1] > k)
				WAR = 1;
		} if (x < N and y > 1) {
			if (GRAF[x + 1][y - 1] == k and !VIS[x + 1][y - 1])
				Q.push({x + 1, y - 1}), VIS[x + 1][y - 1] = 1;
			if (GRAF[x + 1][y - 1] > k)
				WAR = 1;
		} if (x < N) {
			if (GRAF[x + 1][y] == k and !VIS[x + 1][y])
				Q.push({x + 1, y}), VIS[x + 1][y] = 1;
			if (GRAF[x + 1][y] > k)
				WAR = 1;
		} if (x < N and y < N) {
			if (GRAF[x + 1][y + 1] == k and !VIS[x + 1][y + 1])
				Q.push({x + 1, y + 1}), VIS[x + 1][y + 1] = 1;
			if (GRAF[x + 1][y + 1] > k)
				WAR = 1;
		} if (y < N) {
			if (GRAF[x][y + 1] == k and !VIS[x][y + 1])
				Q.push({x, y + 1}), VIS[x][y + 1] = 1;
			if (GRAF[x][y + 1] > k)
				WAR = 1;
		} if (x > 1 and y < N) {
			if (GRAF[x - 1][y + 1] == k and !VIS[x - 1][y + 1])
				Q.push({x - 1, y + 1}), VIS[x - 1][y + 1] = 1;
			if (GRAF[x - 1][y + 1] > k)
				WAR = 1;
		} if (x > 1) {
			if (GRAF[x - 1][y] == k and !VIS[x - 1][y])
				Q.push({x - 1, y}), VIS[x - 1][y] = 1;
			if (GRAF[x - 1][y] > k)
				WAR = 1;
		}
	}
}

void bfsDol(int x, int y, int k) {
	Q.push({x, y});
	VIS[x][y] = 1;

	while (!Q.empty()) {
		x = Q.front().a;
		y = Q.front().b;
		Q.pop();

		if (x > 1 and y > 1) {
			if (GRAF[x - 1][y - 1] == k and !VIS[x - 1][y - 1])
				Q.push({x - 1, y - 1}), VIS[x - 1][y - 1] = 1;
			if (GRAF[x - 1][y - 1] < k)
				WAR = 1;
		} if (y > 1) {
			if (GRAF[x][y - 1] == k and !VIS[x][y - 1])
				Q.push({x, y - 1}), VIS[x][y - 1] = 1;
			if (GRAF[x][y - 1] < k)
				WAR = 1;
		} if (x < N and y > 1) {
			if (GRAF[x + 1][y - 1] == k and !VIS[x + 1][y - 1])
				Q.push({x + 1, y - 1}), VIS[x + 1][y - 1] = 1;
			if (GRAF[x + 1][y - 1] < k)
				WAR = 1;
		} if (x < N) {
			if (GRAF[x + 1][y] == k and !VIS[x + 1][y])
				Q.push({x + 1, y}), VIS[x + 1][y] = 1;
			if (GRAF[x + 1][y] < k)
				WAR = 1;
		} if (x < N and y < N) {
			if (GRAF[x + 1][y + 1] == k and !VIS[x + 1][y + 1])
				Q.push({x + 1, y + 1}), VIS[x + 1][y + 1] = 1;
			if (GRAF[x + 1][y + 1] < k)
				WAR = 1;
		} if (y < N) {
			if (GRAF[x][y + 1] == k and !VIS[x][y + 1])
				Q.push({x, y + 1}), VIS[x][y + 1] = 1;
			if (GRAF[x][y + 1] < k)
				WAR = 1;
		} if (x > 1 and y < N) {
			if (GRAF[x - 1][y + 1] == k and !VIS[x - 1][y + 1])
				Q.push({x - 1, y + 1}), VIS[x - 1][y + 1] = 1;
			if (GRAF[x - 1][y + 1] < k)
				WAR = 1;
		} if (x > 1) {
			if (GRAF[x - 1][y] == k and !VIS[x - 1][y])
				Q.push({x - 1, y}), VIS[x - 1][y] = 1;
			if (GRAF[x - 1][y] < k)
				WAR = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;

	for (int y = 1; y <= N; y ++)
		for (int x = 1; x <= N; x ++)
			cin >> GRAF[x][y];

	int grz = 0, dol = 0;

	for (int y = 1; y <= N; y ++) {
		for (int x = 1; x <= N; x ++) {
			if (!VIS[x][y])
				bfsGrz(x, y, GRAF[x][y]), grz += (WAR == 0);
			WAR = 0;
		}
	}

	for (int y = 1; y <= N; y ++)
		for (int x = 1; x <= N; x ++)
			VIS[x][y] = 0;

	for (int y = 1; y <= N; y ++) {
		for (int x = 1; x <= N; x ++) {
			if (!VIS[x][y])
				bfsDol(x, y, GRAF[x][y]), dol += (WAR == 0);
			WAR = 0;
		}
	}

	cout << grz << ' ' << dol; 
}
