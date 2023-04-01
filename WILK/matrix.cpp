#include <iostream>

using namespace std;

int mat1[500][500], mat2[500][500];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	for (int y = 0; y < a; y ++)
		for (int x = 0; x < b; x ++)
			cin >> mat1[x][y];

	for (int y = 0; y < b; y ++)
		for (int x = 0; x < c; x ++)
			cin >> mat2[x][y];

	for (int y = 0; y < a; y ++) {
		for (int x = 0; x < c; x ++) {
			int sum = 0;
			for (int i = 0; i < b; i ++)
				sum += mat1[i][y] * mat2[x][i];

			cout << sum << ' ';
		}
		cout << '\n';
	}
}