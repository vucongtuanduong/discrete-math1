#include <iostream>
#include <vector>
using namespace std;

int n, k;

void sinh(int cntB, string& x, bool check) {
	if (x.size() == n) {
		cout << x << endl;
		return;
	}

	x.push_back('A');
	sinh(0, x, check);
	x.pop_back();

	if (!check) {
		if (cntB < k - 1) {
			x.push_back('B');
			sinh(cntB + 1, x, check);
			x.pop_back();
		}
		else if (cntB == k - 1) {
			x.push_back('B');
			sinh(cntB + 1, x, true);
			x.pop_back();
		}
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> k;

	string x;
	sinh(0, x, false);

	return 0;
}