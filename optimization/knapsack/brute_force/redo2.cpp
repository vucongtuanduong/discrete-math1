#include <bits/stdc++.h>
using namespace std;
int n, b, fopt;
int a[100];//trong luong
int c[100];//gia tri
int x[100];
int xopt[100];

void input();
bool checkKL();
int tinhGT();
void capnhat(int tong);
void Try(int i);
void inKQ();
//cu the
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            capnhat(tinhGT());
        } else {
            Try(i + 1);
        }
    }
}
int tinhGT() {
    int sum = 0;
    for (int i = 1;i <= n; i++) {
        sum += c[i] * x[i];
    }
    return sum;
}
void capnhat(int tong) {
    if (tong > fopt && checkKL()) {
        fopt = tong;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
bool checkKL() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * x[i];
    }
    if (sum <= b) {
        return true;
    } else {
        return false;
    }
}
void inKQ() {
    cout << "Phuong an toi uu: ";
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] ;
    } 
    cout << "\nGia tri toi uu: " << fopt << endl;
}
void input() {
    cout << "Nhap n:  ";

    cin >> n;
    cout << "Nhap b: " ;
    cin >> b;
    cout << "Nhap khoi luong cac do vat: " ;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    cout << "Nhap gia tri cuar cac do vat: ";
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    input();
    Try(1);
    inKQ();
}