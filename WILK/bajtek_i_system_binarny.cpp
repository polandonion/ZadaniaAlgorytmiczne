#include <iostream>

using namespace std;

void decToBin(int n) {
	if(n == 0) return;
	decToBin(n / 2);
	cout << n % 2;
}

int main() {
	int n;
	cin >> n;
	decToBin(n);
}
