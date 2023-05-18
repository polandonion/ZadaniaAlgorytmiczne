#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void post_order(string pre, string in) {
	if (pre.size() < 1 or in.size() < 1)
		return;

	post_order(pre.substr(1, in.find(pre[0])), in.substr(0, in.find(pre[0])));
	post_order(pre.substr(in.find(pre[0]) + 1), in.substr(in.find(pre[0]) + 1));

	cout << pre[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	while (n --) {
		string pre, in;
		cin >> pre >> in;

		post_order(pre, in);
		cout << '\n';
	}
}