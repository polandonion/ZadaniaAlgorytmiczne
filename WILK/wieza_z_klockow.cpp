#include <iostream>

using namespace std;

int arr[100000];

bool da_sie(int n) {
	int sr = n / 2, i, j;

	if (n % 2 == 0 and arr[sr] < arr[sr - 1])
		sr --;

	i = sr - 1, j = sr + 1;

	if (arr[sr] == 0)
		return 0;

	while (0 <= i or j < n) {
		if (0 <= i) {
			if (arr[i] == 0 or (arr[i] >= arr[i + 1] and arr[i + 1] - 1 <= 0))
				return 0;
			if (arr[i] >= arr[i + 1])
				arr[i] = arr[i + 1] - 1;
		}
		if (j < n) {
			if (arr[j] == 0 or (arr[j] >= arr[j - 1] and arr[j - 1] - 1 <= 0))
				return 0;
			if (arr[j] >= arr[j - 1])
				arr[j] = arr[j - 1] - 1;
		}

		i --, j ++;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int k;
	cin >> k;

	while (k --) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i ++)
			cin >> arr[i];

		if (da_sie(n))
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}