#include <iostream>

using namespace std;

short fnNwd(long long a, long long b) {
	if(b == 0) return a;
	return fnNwd(b, a % b);
}

long long fnNww(long long a, long long b) {
	return a * b / fnNwd(a, b);
}

int main() {
	short n, nwd;
	long long a, b, nww = 1;
	cin >> n >> a >> b;
	a++; b++;
	nwd = fnNwd(a, b);
	nww = fnNww(a, b);
	for(int i = 2; i < n; i++) {
		cin >> a;
		a++;
		nww = fnNww(nww, a);
	}
	cout << nww - 1;
}
