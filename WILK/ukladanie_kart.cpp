#include <iostream>

using namespace std;

int arr[1000000];
int pom[1000000];
long long inv = 0;

void _merge(int l, int mid, int r) {
	int i1 = l, i2 = mid + 1;

	int prz = 0;
	for (int i = l; i <= r; i ++) {
		if (i1 <= mid and i2 <= r) {
			if (arr[i1] > arr[i2]) {
				inv += (long long)i2 - i1 - prz;
				prz ++;
				pom[i] = arr[i2 ++];
			}
			else
				pom[i] = arr[i1 ++];
		}
		else {
			if (i1 > mid)
				pom[i] = arr[i2 ++];
			else
				pom[i] = arr[i1 ++];
		}
	}

	for (int i = l; i <= r; i ++)
		arr[i] = pom[i];
}

void _sort(int l, int r) {
	if (l == r)
		return;

	int mid = (l + r) / 2;
	_sort(l, mid);
	_sort(mid + 1, r);

	_merge(l, mid, r);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i ++)
		cin >> arr[i];

	_sort(0, n - 1);

	cout << inv;
}
