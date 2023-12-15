#include <iostream>
using namespace std;
int n, k;
int x[100];
void result() {
    for (int i = 1; i <= k; i++) {
        cout << x[i] ;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    Try(1);
}