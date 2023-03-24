#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

vector <pair <int, int>> v[5001];
vector <pair <int, int>> vR[5001];
priority_queue <pair <int, int>> q;
int dis[5001], disTo1[5001], val[5001];
bool vis[5001];
const int INF = 1e9 + 1;
int n;

void dij(int w) {
	for (int i = 2; i <= n; i ++)
		dis[i] = INF;
	dis[1] = 0;

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

void dijV2(int w) {
	for (int i = 2; i <= n; i ++)
		disTo1[i] = INF;
	disTo1[1] = 0;

	q.push({0, w});
	while (!q.empty()) {
		w = q.top().y;
		q.pop();

		if (vis[w])
			continue;
		vis[w] = 1;

		for (auto a : vR[w]) {
			disTo1[a.x] = min(disTo1[a.x], disTo1[w] + a.y);
			if (!vis[a.x])
				q.push({-disTo1[a.x], a.x});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> val[i];

	int k;
	cin >> k;
	while (k --) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		vR[b].push_back({a, c});
	}

	dij(1);

	for (int i = 1; i <= n; i ++)
		vis[i] = 0;

	dijV2(1);

	int mn = INF;

	for (int i = 1; i <= n; i ++)
		mn = min(mn, dis[i] + disTo1[i] + val[i] / 2);

	cout << mn;
}