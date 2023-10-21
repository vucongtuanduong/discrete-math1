#include <iostream>
using namespace std;
int n;
int c[20][20];//ma tran chi phi
int x[20];//phuong an duyet
int xopt[20];//phuong an toi uu
int fopt;//chi phi toi uu
bool unused[20];//duyet hoan vi
void init();
int totalCost();
void update(int cost);
void Try(int i);
void display();

void init() {
    cout << "Nhap so luong thanh pho: ";
    cin >> n;
    cout << "Nhap ma tran chi phi: ";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    fopt = 1e9;


    for (int i = 1; i <= n; i++) {
        unused[i] = true;
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
void update(int cost) {
    if (cost < fopt) {
        fopt = cost;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                int cost = totalCost();
                update(cost);
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}
void display() {
    cout << "\nChi phi toi uu: " << fopt << endl;
    cout << "Phuong an toi uu: ";
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] << " ";
    }
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif
    init();
    Try(1);
    display();
    return 0;
}