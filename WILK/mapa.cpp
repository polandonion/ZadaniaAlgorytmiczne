#include <bits/stdc++.h>

using namespace std;

vector <int> v[1000009];
int vis[1000009], c = 0, ile = 0;
int n, m;

//vis[i] = 0  =>  nieodwiedzone
//vis[i] = 1  =>  odwiedzone
//vis[i] = 2  =>  aktualnie odwiedzane

void dfs(int w) {
	vis[w] = 2;
	ile ++;

	for (int k : v[w]) {
		if (!vis[k])
			dfs(k);
		else if (vis[k] == 2 and ile > 1) {
			//cout << k << ' ';
			c = 1;
		}
	}

	ile --;
	vis[w] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	while (m --) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i ++)
		dfs(i);
	if (c) cout << "TAK";
	else cout << "NIE";
}
