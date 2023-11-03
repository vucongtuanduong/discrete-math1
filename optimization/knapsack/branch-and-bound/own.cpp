#include <iostream>
using namespace std;

int a[100], c[100], x[100], xopt[100];
int n, b, fopt, deltak, bk, gk;

void init();
void update();
void result();
void branch_and_bound(int k);

void init() {
    cout << "Enter n: \n";
    cin >> n;
    cout << "Enter b: \n";
    cin >> b;
    bk = b;
    cout << "Enter weights: \n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << "Enter values: \n";
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    fopt = 0;
}

void update() {
    if (deltak > fopt) {
        fopt = deltak;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}

void result() {
    cout << "Optimal value: " << fopt << "\n";
    cout << "Selected items: \n";
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] << " ";
    }
}

void branch_and_bound(int k) {
    for (int i = 1; i >= 0; i--) {
        x[k] = i;
        deltak = deltak + x[k] * c[k];
        bk = bk - x[k] * a[k];

        // Calculate the potential bound gk
        if (k == n) {
            if (bk >= 0) {  // Check if bk is non-negative before updating
                update();
            }
        } else {
            gk = deltak + bk * c[k + 1] / a[k + 1];
            if (gk > fopt && bk > 0) {
                branch_and_bound(k + 1);
            }
        }

        deltak = deltak - x[k] * c[k];
        bk = bk + x[k] * a[k];
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    init();
    branch_and_bound(1);
    result();
}
