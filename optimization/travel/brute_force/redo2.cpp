#include <iostream>
using namespace std;
int n;
int c[20][20];//ma tran chi phi
int x[20];//phuong an duyet
int xopt[20];//phuong an toi uu
int fopt;//chi phi toi uu
bool unused[20];//duyet hoan vi
void init();
void result();
int totalCost();
void update(int cost);
void Try(int i);

// cu the
void init() {
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap ma tran chi phi: ";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
        
    }
    fopt = 1e9;
    unused[1] = false;
    x[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        unused[i] = true;
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            x[i]  = j;
            if (i == n) {
                update(totalCost());
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void result() {
    cout << "Phuong an toi uu: ";
    xopt[n + 1] = 1;
    for (int i =1; i <= n + 1; i++) {
        cout << xopt[i];
    }
    cout << "\nGia tri toi uu: " << fopt << endl;
}
void update(int cost) {
    if (cost <fopt) {
        fopt = cost;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
int totalCost() {
    int res = 0;
    for (int i = 1; i < n; i++) {
        res += c[x[i]][x[i + 1]];
    }
    res += c[x[n]][x[1]];
    return res;
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    #endif
    init();
    Try(2);
    result();
    return 0;
}