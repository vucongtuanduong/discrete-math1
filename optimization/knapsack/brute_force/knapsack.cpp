#include <iostream>
#include <climits>
using namespace std;

int n, b, x[100], xopt[100];
int a[100];//trong luong
int c[100];//gia tri su dung
int fopt;
void input() {
    cin >> n;
    cin >> b;
    fopt = INT_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
}
bool checkKL() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * x[i];
        if (sum > b) {
            return false;
        }
    }
    return true;
}
int tinhGT() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += c[i] * x[i];
    }
    return sum;
}
void capnhat() {
    int gtsd = tinhGT();
    if (gtsd > fopt && checkKL()) {
        fopt = gtsd;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}

void inKq() {
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] << " ";
    }
    cout << endl;
    cout << "Gia tri su dung toi uu: " << fopt << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            capnhat();
        } else {
            
            Try(i + 1);
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    #endif
    input();
    Try(1);
    inKq();
}