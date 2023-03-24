#include <bits/stdc++.h>

using namespace std;

vector <int> v[1000009];
queue <int> q;
int vis[1000009];
int n, m, c = 0;

void dfs(int w) {
	for (int k : v[w]) {
		if (!vis[k]) {
			vis[k] = vis[w] + 1;
			dfs(k);
		}
		else if (vis[w] - vis[k] > 1)
			c = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	while (m --) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			vis[j] = 0;
		vis[i] = 1;
		dfs(i);
	}
	
	if (c) cout << "TAK";
	else cout << "NIE";
}
