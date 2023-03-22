#include <iostream>

using namespace std;

short zij(int n, short i) {
	if(n) {
		if(n % 10 < 2) i ++;
		return zij(n / 10, i);
	}
	return i;
}

int main() {
	int n;
	cin >> n;
	cout << zij(n, 0);
}
