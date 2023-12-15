#include <bits/stdc++.h>
using namespace std;
vector<int> x;
vector<int>res;
int n, k;
void result() {
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
}

void Try(int i) {
    if (res.size() == k) {
        result();
    } else {
        if (i < n) {
            if (res.empty() || res[res.size() - 1] > x[i]) {
                res.push_back(x[i]);
                Try(i + 1);
                res.pop_back();
            }
            Try(i + 1);
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> k;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end(), greater<int>());
    Try(0);
}