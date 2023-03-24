#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
		cin >> arr[i];
		
	int p, k;
	cin >> p >> k;
	
	bool war = 1;
	for (int i = p, j = k; i <= j; i ++, j --) {
		if (arr[i] != arr[j])
			war = 0;
	}
	
	if (!war)
		cout << "NIE";
	else
		cout << "TAK";
}
