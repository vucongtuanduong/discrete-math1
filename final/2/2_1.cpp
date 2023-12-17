#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[100];
void result(int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int i,int sum) {
    for (int j = x[i - 1] ; j >= 1; j--) {
        if (sum + j <= n) {
            x[i] = j;
            sum += x[i];
            if (sum == n) {
                result(i);
            } else {
                Try(i + 1, sum);
            }
            sum -= x[i];
        }
        
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    cin >> n;
    x[0] = n - 1;
    Try(1, 0);
}