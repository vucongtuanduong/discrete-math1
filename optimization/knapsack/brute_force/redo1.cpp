#include <bits/stdc++.h>
using namespace std;
int n, b, fopt;
int a[100];//trong luong
int c[100];//gia tri
int x[100];
int xopt[100];

void init();
void Try(int i);
void result();
void update(int value);
int totalValue();
bool isFull();
//cu the
bool isFull() {
    int bk = 0;
    for (int i = 1; i <= n; i++) {
        bk += x[i] * a[i];
    }
    if (bk <= b) {
        return false;
    } else {
        return true;
    }
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            if (!isFull()) {
                update(totalValue());
            }
            
        } else {
            // cout << "TRy" << i + 1 << endl;
            Try(i + 1);
        }

    }
}
int totalValue() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += x[i] * c[i];
    }
    return res;
}
void init() {
    cin >> n;
    cin >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    fopt = -1e9;
}
void result() {
    cout << "Phuong an toi uu: ";
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] << " ";
    }
    cout << "\nGia tri toi uu: " << fopt << endl;
}
void update(int value) {

    if (value > fopt) {
        fopt = value;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    Try(1);
    result();
}