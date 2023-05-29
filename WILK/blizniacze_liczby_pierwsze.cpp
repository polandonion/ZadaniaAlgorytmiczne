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
	int a, b;
	cin >> a >> b;
	
	sito(b);
	
	int ile = 0;
	for (; a <= b - 2; a ++)
		if (!zlozona[a] and !zlozona[a + 2])
			ile ++;
	
	cout << ile;
}