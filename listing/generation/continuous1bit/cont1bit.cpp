#include <iostream>
using namespace std;
void init(int *a, int n, int k);
void genNext(int *a, int n, int k);
bool isFinal(int *a, int n, int k);
void display(int *a, int n, int k);
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int *a = new int[100];
    // init(a, n, k);
    // while (!isFinal(a, n ,k)) {
    //     display(a, n, k);
    //     genNext(a, n, k);
    // }
    // display(a, n, k);

    // cout << n << " " << k << endl;
    // a[1] = a[2]= a[3] = 1;
    // a[4] = 0;
    // a[5] = a[6] = a[7] = 1;
    // a[8] = 0;
    // a[9] = a[10]= a[11] = 1;
    // a[12] = 0;
    // cout << isFinal(a, n, k);
}
void init(int *a, int n, int k){
    int t = n;
    int e = k;
    while (e--) {
        a[t] = 1;
        t--;
    }
    for (int i = 1; i <= n - k; i++) {
        a[i] = 0;
    }
}
bool isFinal(int *a, int n, int k) {
    cout << n << " " << k << endl;for (int i = 1; i <= k; i++) {
        if (a[i] == 0) {
            return false;
        }
    }

    bool is0 = true;
    bool is1 = false;
    bool ok = true;
    int m = k + 1;
    // cout << m << endl;
    while (m <= n) {
        if (a[m] == 0) {
            is0 = true;
            is1 = false;
        } else {
            return false;
        }
        int s = m + k;
        int r = min(s, n);
        for (int j = m + 1; j <= r; j++) {
            if (is0 && a[j] == 0) {
                return false;
            } else if (is1 && a[j] == 0) {
                return false;
            } else if (is0 && a[j] == 1) {
                is0 = false;
                is1 = true;
            }
        }
        m += (k + 1);
    }
    return true;
}
void display(int *a, int n, int k) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void genNext(int *a, int n, int k) {

}