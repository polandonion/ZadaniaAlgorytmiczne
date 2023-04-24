#include <iostream>
#include <algorithm>

using namespace std;

int des[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++)
		cin >> des[i];
			
	sort(des, des + n);
	
	if (n < 4) {
		cout << 0;
		return 0;
	}
	
	int des1 = -1, des2 = -1;
	for (int i = n - 2; i >= 0; i --) {
		if (des[i] == des[i + 1]) {
			if (des1 > 0) {
				des2 = des[i];
				break;
			}
			
			des1 = des[i];
			i --;
		}
	}
	
	if (des1 > 0 and des2 > 0)
		cout << (long long)des1 * des2;
		
	else
		cout << 0;
}