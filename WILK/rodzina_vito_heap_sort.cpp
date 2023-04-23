#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[10000001], N, n;

void kopcuj(int v) {
	int tmp = v;

	if (2 * v <= n and arr[2 * v] > arr[tmp])
		tmp = 2 * v;

	if (2 * v + 1 <= n and arr[2 * v + 1] > arr[tmp])
		tmp = 2 * v + 1;


	if (v != tmp) {
		swap(arr[v], arr[tmp]);

		kopcuj(tmp);
	}
}

void buduj_kopiec() {
	for (int i = N / 2; i >= 1; i --)
		kopcuj(i);
}

void sortuj() {
	for (int i = 1; i < N; i ++) {
		swap(arr[1], arr[n]);
		n --;

		kopcuj(1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	n = N;

	for (int i = 1; i <= N; i ++)
		cin >> arr[i];

	buduj_kopiec();

	sortuj();

	int idx = (N + 1) / 2;
	long long dis = 0;

	for (int i = 1; i <= N; i ++)
		dis += (long long)abs(arr[i] - arr[idx]);
	cout << dis;
}
