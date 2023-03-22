#include <bits/stdc++.h>

using namespace std;

void genFibNum(int n);
int fac(int n, int last);

vector <int> fib = {1, 2};
vector <int> fibSuf = {1};

int main() {
	int n;
	cin >> n;

	genFibNum(n);

	cout << fac(n, fib.size() - 1);
}

void genFibNum(int n) {
	while (fib.back() < n) {
		fib.push_back(fib.back() + fib[fib.size() - 2]);
		fibSuf.push_back(fibSuf.back() + fib[fibSuf.size()]);
	}
		
	fib.pop_back();		
}

int fac(int n, int last) {
	if (n == 0)
		return 1;
 
	int sum = 0;
 
	for (int i = last; i >= 0; i --) {
		if (fib[i] > n)
			continue;

		if (fibSuf[i] < n)
			break;
 
		sum += fac(n - fib[i], i - 1);
	}
 
	return sum;
}
