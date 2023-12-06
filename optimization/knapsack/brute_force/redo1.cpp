#include <bits/stdc++.h>
using namespace std;
int n, b, fopt;
int a[100];//trong luong
int c[100];//gia tri
int xopt[100];

void init();
void Try(int i);
void result();
void update(int value);
int calCost();
bool isFull();
//cu the
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
    cout << "Gia tri toi uu: " << fopt << endl;
}
void update(int value) {
    if (value > fopt) {
        
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