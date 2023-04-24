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
	
	int max_bok = 0;
	
	max_bok = des[n - 1] / 4;
	
	if (n > 1) {
		max_bok = max(max_bok, des[n - 2] / 2);
		max_bok = max(max_bok, min(des[n - 1] / 3, des[n - 2]));
	}
	
	if (n > 2)
		max_bok = max(max_bok, min(des[n - 3], des[n - 1] / 2));
		
	if (n > 3)
		max_bok = max(max_bok, des[n - 4]);
		
	cout << (long long)max_bok * max_bok;
}