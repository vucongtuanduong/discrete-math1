#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void in(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void sinh(int n, int max, vector<int>& v) {
	if (n == 0) {
		in(v);
		return;
	}

	for (int i = min(n, max); i >= 1; i--) {
		v.push_back(i);
		sinh(n - i, i, v);
		v.pop_back();
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	vector<int> v;
	sinh(n, n - 1, v);//bat dau bang n - 1 1
    //sinh (n, n , v);//bat dau bang n 0

	return 0;
}