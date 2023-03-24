#include <bits/stdc++.h>

#define x first
#define y second

#define INF 10000001

using namespace std;

vector <pair <int, int>> v[1001];
priority_queue <pair <int, int>> q;
int dis[1001];
bool vis[1001];

void dijkstra(int w, int n) {
	for (int i = 1; i <= n; i ++)
		dis[i] = INF;

	dis[w] = 0;
	q.push({0, w});

	while (!q.empty()) {
		w = q.top().y;
		q.pop();

		if (vis[w])
			continue;
		vis[w] = 1;

		for (auto a : v[w]) {
			dis[a.x] = min(dis[a.x], dis[w] + a.y);
			if (!vis[a.x])
				q.push({-dis[a.x], a.x});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	while (k --) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	dijkstra(1, n);

	if (dis[n] < INF)
		cout << dis[n];
	else
		cout << -1;
}
