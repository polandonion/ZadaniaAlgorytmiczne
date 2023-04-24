#include <iostream>
#include <algorithm>

using namespace std;

int des[1000000];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++)
		cin >> des[i];
		
	sort(des, des + n);
	
	if (n > 3)
		cout << (long long)des[n - 4] * des[n - 4];
	else
		cout << 0;
}