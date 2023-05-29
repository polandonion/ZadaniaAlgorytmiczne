#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000000];

int main() {
	long long n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i ++)
		cin >> arr[i];
		
	sort(arr, arr + n);
	long long i;
	for (i = k; i <= arr[n - 1]; i += k) {
		if (binary_search(arr, arr + n, i) == 0) {
			cout << i;
			return 0;
		}
	}
	cout << i;
}