#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int x[100];
int a[100];
int np[100];

void init() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    cin >> n >> k;

}
void result() {
    for (int i = 1; i <= k; i++) {
        cout << a[i];
    }
    cout << endl;
}
bool check() {
    int count = 0;
    for (int i = 1; i <= m; i++) {
        if (np[i]) {
            count++;
        }
        
    }
    if (count == k) {
        int res = 0;
        int j = 1;
        for (int i = 1; i <= m; i++) {
            if (np[i]) {
                a[j++] = x[i];
            }
            if (j == k + 1) {
                break;
            }
        }
        for (int i = 1; i <= k; i++) {
            res += a[i];
        }
        return res == n;
    } else {
        return false;
    }
}
void Try(int i) {

    for (int j = 0; j <= 1; j++) {
        np[i] = j;
        if (i == m) {
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
    init();
    Try(1);
}