#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int arr[1000001];
int lew[1000001], pra[1000002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i ++)
		cin >> arr[i];

	for (int i = 2; i <= n; i ++)
		lew[i] = (arr[i] - arr[i - 1] >= 0 ? lew[i - 1] + 1 : 0);
	
	for (int i = n - 1; i >= 1; i --)
		pra[i] = (arr[i] - arr[i + 1] >= 0 ? pra[i + 1] + 1 : 0);

	int mx = 0;
	for (int i = 1; i <= n; i ++)
		mx = max(mx, 1 + lew[i] + pra[i]);

	cout << mx; 
}
