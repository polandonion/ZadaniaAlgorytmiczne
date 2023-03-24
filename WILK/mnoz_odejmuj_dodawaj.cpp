#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <long long> stc;

long long wyn(string str) {
	long long tmp = 0;

	for (int i = 0; i < str.size(); i ++) {
		if (str[i] >= '0' and str[i] <= '9')
			tmp = tmp * 10 + str[i] - '0';

		else if (str[i] == ' ' and str[i - 1] >= '0' and str[i - 1] <= '9') {
			stc.push(tmp);
			tmp = 0;
		}

		else if (str[i] == 'M' or str[i] == 'O' or str[i] == 'D'){
			long long b = stc.top();
			stc.pop();

			long long a = stc.top();
			stc.pop();

			switch(str[i]) {
				case 'M': stc.push(a * b); break;
				case 'O': stc.push(a - b); break;
				case 'D': stc.push(a + b); break;
			}
		}
	}

	return stc.top();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	//cin.ignore();
	string tmp;
	getline(cin, tmp);

	while (n --) {
		string str;
		getline(cin, str);

		cout << wyn(str) << '\n';
	}
}
