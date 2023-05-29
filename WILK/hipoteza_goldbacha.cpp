#include <iostream>

using namespace std;

bool zlozona[100000000];

void sito(int n) {
	for (int i = 2; i * i <= n; i ++) {
		if (!zlozona[i]) {
			for (int j = i * i; j <= n; j += i)
				zlozona[j] = 1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	sito(n);
	
	int ile = 0;
	for (int i = 2; i <= n / 2; i ++)
		if (!zlozona[i] and !zlozona[n - i])
			ile ++;
	
	cout << ile;
}