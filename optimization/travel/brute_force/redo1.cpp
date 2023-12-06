#include <bits/stdc++.h>
using namespace std;
int n, fopt;
int c[100][100];//gia tri
int x[100];
int xopt[100];
bool unused[100];

void init();
void Try(int i);
void result();
void update(int cost);
int totalCost();
//cu the
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            unused[j] = false;
            x[i] = j;
            if (i == n) {
                update(totalCost());
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
        
        

    }
}
int totalCost() {
    int res = 0;
    for (int i = 1; i <= n - 1; i++) {
        res += c[x[i]][x[i + 1]];
    }
    res += c[x[n]][x[1]];
    return res;
}
void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    unused[1] = false;
    x[1] = 1;
    for (int i = 2; i <= n; i++) {
        unused[i] = true;
    }
    fopt = 1e9;
}
void result() {
    xopt[n + 1] = xopt[1] = 1;
    cout << "Phuong an toi uu: ";
    for (int i = 1; i <= n + 1; i++) {
        cout << xopt[i] << " ";
    }
    cout << "\nChi phi toi uu: " << fopt << endl;
}
void update(int cost) {

    if (cost < fopt) {
        fopt = cost;
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
    Try(2);
    result();
}