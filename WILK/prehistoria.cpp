#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, q, kol = 1;

vector <int> v[1000009];

int vis[1000009];

void dfs(int w) {
	vis[w] = kol;
	for (int i = 0; i < v[w].size(); i ++) {
		if (vis[v[w][i]] == 0) {
			dfs(v[w][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < m; i ++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i] == 0) {
			dfs(i);
			kol ++;
		}
		//cout << i << ' ' << vis[i] << '\n';
	}
	cin >> q;
	while (q --) {
		cin >> a >> b;
		if (vis[a] == vis[b]) cout << "TAK\n";
		else cout << "NIE\n";
	}
}
