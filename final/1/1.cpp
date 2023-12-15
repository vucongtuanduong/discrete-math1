#include <iostream>
using namespace std;

int n, k;
int x[100] = { 0 };

void in() {
	int nhi_phan[100] = { 0 };
    cout << "x: \n";
    for (int i = 1; i <= k; i++) {
        cout << x[i];
    }
    cout << endl;
	for (int i = 1; i <= k; i++) {
		nhi_phan[x[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << nhi_phan[i];
	}
	cout << endl;
}

void sinh(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) in();
		else sinh(i + 1);
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> n >> k;
	sinh(1);

	return 0;
}