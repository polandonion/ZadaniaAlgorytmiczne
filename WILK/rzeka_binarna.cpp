#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void inOrder(int n, int i) {
	if(n == 0) return;
    inOrder(n - 1, i * 2);
    cout << i << ' ';
    inOrder(n - 1, i * 2 + 1);
}

void preOrder(int n, int i) {
	if(n == 0) return;
    cout << i << ' ';
    preOrder(n - 1, i * 2);
    preOrder(n - 1, i * 2 + 1);
}

void postOrder(int n, int i) {
	if(n == 0) return;
    postOrder(n - 1, i * 2);
    postOrder(n - 1, i * 2 + 1);
    cout << i << ' ';
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    (s == "IN" ? inOrder(n, 1) : (s == "PRE" ? preOrder(n, 1) : postOrder(n, 1)));
}
