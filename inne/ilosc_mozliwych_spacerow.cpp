#include <iostream>
#include <vector>

using namespace std;

vector <int> v[1000000];
bool odw[1000000], sasiad_z_1[1000000];

int n, m, a, b, ile_drog = 0, ile_odw = 0;

void dfs(int w) {
    odw[w] = 1; ile_odw ++;
    for (unsigned int i = 0; i < v[w].size(); i ++) {
        if (odw[v[w][i]] == 0)
            dfs(v[w][i]);
    }
    if (ile_odw == n and sasiad_z_1[w] == 1)
            ile_drog ++;
    odw[w] = 0; ile_odw --;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        if (a == 1) sasiad_z_1[b] = 1;
        else if (b == 1) sasiad_z_1[a] = 1;

    }
    dfs(1);
    cout << ile_drog;
}
