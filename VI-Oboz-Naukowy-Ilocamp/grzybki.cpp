#include <bits/stdc++.h>

using namespace std;

struct Grzyb {
	int a, b, c;
    // a - masa, b - przyrost, c - dni zycia
};

unordered_map <int, pair <long long, long long>> m;
Grzyb a[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long su = 0, prz = 0, mxDz = 0;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i].a >> a[i].b >> a[i].c;

        mxDz = max(mxDz, (long long)a[i].c);

        su += (long long)a[i].a; // suma poczatkowa
        prz += (long long)a[i].b; // przyrost poczatkowy

        m[a[i].c].first += ((long long)a[i].c - 1) * a[i].b + a[i].a;
        m[a[i].c].second += (long long)a[i].b;
    }

    long long sum = 0, dz = 1;
    for (int i = 1; i <= mxDz; i ++) {
        su += prz;
        if (m.find(i) != m.end())
            su -= m[i].first + m[i].second, prz -= m[i].second;

        //cout << su << ' ';
        if (su > sum)
            sum = su, dz = i;
    }

    cout << dz;
}