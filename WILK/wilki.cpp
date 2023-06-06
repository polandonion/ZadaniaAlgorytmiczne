#include <iostream>
#include <stack>
#include <utility>

using namespace std;

stack <pair <int, char> > stos;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int a;
		char b;
		
		cin >> a >> b;
		
		if (b == 'E')
			stos.push({a, b});
		else {
			while (stos.size() > 0 and stos.top().second == 'E' and stos.top().first < a)
				stos.pop();
			
			if (stos.size() == 0 or stos.top().second == 'W')
				stos.push({a, b});
		}
	}
	
	cout << stos.size();
}