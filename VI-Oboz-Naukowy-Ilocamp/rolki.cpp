#include <bits/stdc++.h>

using namespace std;

int n, optDlug, maxRozw = 1e9;
int dlug[1000001], rozw[1000001];
long long wynik = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> dlug[i] >> rozw[i];

    for (int i = 1; i <= n; i ++)
        maxRozw = min(maxRozw, dlug[i]);

    sort(rozw, rozw + n + 1);
    if (n % 2 == 1)
        optDlug = rozw[n / 2 + 1];
    else
        optDlug = (rozw[n / 2] + rozw[n / 2 + 1]) / 2;
    if (optDlug > maxRozw)
        optDlug = maxRozw;

    for (int i = 1; i <= n; i ++)
        wynik += abs(optDlug - rozw[i]);

    cout << wynik;
}