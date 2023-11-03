#include <iostream>
using namespace std;
int n, cmin, c[100][100], xopt[100], fopt, deltak;
bool unused[100];
int x[100];

void init();
void display();
void branch_and_bound(int k);
void update();
void find_min();

void find_min() {
    cmin = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] < cmin) {
                cmin = c[i][j];
            }
        }
    }
}
void init() {
    cout << "Nhap n: \n";
    cin >> n;
    cout << "Nhap ma tran chi phi: \n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    } 
    unused[1] =false;
    find_min();
    x[1] = x[n + 1] =  1;
    xopt[n + 1] = 1;
    for (int i = 2; i <= n; i++) {
        unused[i] = true;
    }
    deltak = 0;
    fopt = 1e9;
}
void display() {
    cout << "Chi phi toi uu: " << fopt << endl;
    cout << "Lo trinh toi uu: " << endl;
    for (int i = 1; i <= n + 1; i++) {
        cout << xopt[i] << " ";
    }
}
void branch_and_bound(int k) {
    for (int j = 2; j <= n; j++) {
        if (unused[j] == true) {
            x[k] = j;
            unused[j] = false;
            deltak = deltak + c[x[k - 1]][x[k]];
            if (k == n) {
                update();
            } else if (deltak + (n - k + 1) * cmin < fopt) {
                branch_and_bound(k + 1);
            }
            unused[j] = true;
            deltak = deltak - c[x[k - 1]][x[k]];

        }
    }
}

void update() {
    if (deltak + c[x[n]][x[1]] < fopt) {
        fopt = deltak + c[x[n]][x[1]];
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    init();
    branch_and_bound(2);
    display();
}