#include <bits/stdc++.h>
using namespace std;
int n,k;
int x[100];
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
bool check() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            count++;
        }
    }
    return count == k;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            if (check()) {
                result();
            }
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    Try(1);
}