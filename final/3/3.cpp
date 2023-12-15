#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
int n, k;

void in(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void find(int i, int sum, vector<int>& v) {
	if (sum < 0) return;
	else
		if (sum == 0) {
			if (v.size() == k) in(v);
		}
		else if (i < N) {
			v.push_back(arr[i]);
			find(i + 1, sum - arr[i], v);
			v.pop_back();
			find(i + 1, sum, v);
		}
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
	cin >> n >> k;

	vector<int> v;
	find(0, n, v);

	return 0;
}