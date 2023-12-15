#include <bits/stdc++.h>
using namespace std;
//vector<pair<int,int>> xopt;
// vector<pair<int,int>> x;
int xopt[100];
vector<pair<int,int>> tui;
int a[100], c[100];
int x[100];
int n, b, bk, deltak, fopt;
double gk;
void init();
void update();
bool cmp(pair<int,int> a, pair<int,int> b);
void branch_and_bound(int k);
void result();
//cu the
void update() {
    if (deltak > fopt) {
        fopt = deltak;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
void result() {
    cout << "Phuong an toi uu: " ;
    for (int i = 0; i < n; i++) {
        cout << xopt[i];
    }
    cout << "\nGia tri toi uu: " << fopt << endl;
}
bool cmp(pair<int,int> a, pair<int,int> b) {
    return (a.second * 1.0  / a.first) > (b.second * 1.0 / b.first);
}
void init() {
    cout << "Nhap n: " ;
    cin >> n;
    cout << "Nhap b: ";
    cin >> b;
    bk = b;
    cout << "Nhap khoi luong do vat: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fopt = 0;
    cout << "Nhap gia tri cua do vat trong tui: ";
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        tui.push_back(make_pair(a[i], c[i]));
    }
    sort(tui.begin(), tui.end(), cmp);
//    for (auto x : tui) {
//        cout << x.first << " " << x.second << endl;
//    }
    
}
void branch_and_bound(int k) {
    for (int j = 1; j >= 0;  j--) {
        x[k] = j;
        deltak = deltak + tui[k].second * x[k];
        bk = bk - tui[k].first * x[k];
        if (k == n) {
            if (bk >= 0) {
                update();
            }
        } else {
            gk = deltak + bk * tui[k + 1].second * 1.0 / tui[k + 1].first;
            if (gk > fopt && bk >= 0) {
                branch_and_bound(k + 1);
            }
        }
        deltak = deltak - tui[k].second * x[k];
        bk = bk + tui[k].first * x[k];
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    init();
    branch_and_bound(0);
    result();
}