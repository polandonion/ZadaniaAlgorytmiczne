#include <bits/stdc++.h>

using namespace std;

int n, a, ile = 0;
vector <int> v[30001];
bool vis[30001];

void dfs(int w) {
    vis[w] = 1;
    for (int k : v[w]) {
        if (!vis[k])
            dfs(k);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a;
        v[i].push_back(a);
    }
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            ile ++;
            dfs(i);
        }
    }
    cout << ile;
}
