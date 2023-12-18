#include <iostream>
using namespace std;
int n,k;
int c[20][20];//ma tran chi phi
int x[20];//phuong an duyet
int a[20];
int fopt;//chi phi toi uu
bool unused[20];//duyet hoan vi
void init();
int totalCost();
void update(int cost);
void Try(int i);
void display();

void init() {
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap ma tran chi phi: ";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    cout << "Nhap k: ";
    cin >> k;


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
bool check() {
    int cost = totalCost();
    if (cost == k) {
        int j = 1;
        for (int i = 1; i < n; i++) {
            a[j++] = c[x[i]][x[i + 1]];
        }
        a[j++] = c[x[n]][x[1]];
        return true;
    }  else {
        return false;
    }
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j] == true) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                if (check()) {
                    result();
                }
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
    }
}

int main (){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    #endif
    init();
    Try(1);
    return 0;
}