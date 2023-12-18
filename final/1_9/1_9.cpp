#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[100];
int a[100];
int b[100];
const int MAX = 1e5 + 1;
int prime[MAX] = {0};
bool unused[100];
void sieve() {
    prime[0] = 1;
    prime[1] = 1;
    for (int i = 2; i < sqrt(MAX); i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = 1;
            }
        }
    }
}
bool check() {
    for (int i = 1; i <= n; i++) {
        a[i] = x[b[i]];
    }
    for (int i  =1 ; i <= n - k + 1; i++) {
        int res = 0;
        for (int m = i; m < i + k; m++) {
            res += a[m];
        }
        if (prime[res] == 1) {
            return false;
        }
    }
    return true;
}
void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i =1; i <= n; i++) {
        unused[i] = true;
    }
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            b[i] = j;
            unused[j] = false;
            if (i == n) {
                if (check()) {
                    result();
                }
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    init();
    sieve();
    Try(1);
}