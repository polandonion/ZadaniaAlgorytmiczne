#include <iostream>

using std::cin;
using std::cout;

long long q = 1e9 + 7;

long long fib[1000001];

long long f(long long n) {
	if(fib[n] == 0) fib[n] = (f(n - 1) + f(n - 2)) % q;
	return fib[n];
}

int main() {
	long long n;
	cin >> n;
	fib[1] = fib[2] = 1;
	cout << f(n);
}
