#include <bits/stdc++.h>
using namespace std;
int n, w, k;
int a[100];
int x[100];
int c[100];
void init() {
    cout << "nhap n: ";
    cin >> n;
    cout << "nhap w: ";
    cin >> w;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Nhap mang a: ";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Nhap mang c: ";
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
}
bool check() {
    int res = 0;
    int wk = w;
    for (int i = 1; i <= n; i++) {
        wk -= a[i] * x[i];
        if (wk < 0) {
            return false;
        }
        res += c[i] * x[i];
    }
    return res == k;
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
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
    init();
    Try(1);
}