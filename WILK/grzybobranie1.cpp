#include <iostream>

using namespace std;

long long arr[1000001];

int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q, x, r;
	long long res;
	cin >> n >> q;
	cin >> x;
	arr[0] = 0;
	arr[1] = x;
	for(int i = 2; i <= n; i++){
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	for(int i = 0; i < q; i++){
		cin >> x >> r;
		res = arr[min(x + r, n)] - arr[max(x - r - 1, 0)];
		cout << res << '\n';
	}
}
