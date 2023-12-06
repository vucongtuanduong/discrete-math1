#include <bits/stdc++.h>
using namespace std;
int x[100], n;
void result();
void Try(int i);
//cu the
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] ;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            result();
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    Try(1);
}