#include <bits/stdc++.h>
using namespace std;
//Liệt kê các dãy con của dãy số 𝐴𝑛 sao cho tổng các phần tử của dãy con đó
//đúng bằng 𝑘
int n, k;
int m;
int np[100];
int x[100];
int a[100];
void init() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
}
void result(int m) {
    for (int i = 1; i <= m; i++) {
        cout << a[i];
    }
    cout << endl;
}
bool check(int m) {
    int count = 0;
    for (int i = 1 ; i <= n; i++) {
        if (np[i] == 1) {
            count++;
        }
    }
    if (count == m) {
        int j = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (np[i] == 1) {
                a[j++] = x[i];
                
            }
            if (j == m + 1) {
                break;
            }
        }
        for (int i = 1; i <= m; i++) {
            sum += a[i];
        }
        return sum == k;
    }else {
        return false;
    }
}
void Try(int i, int m) {
    for (int j = 0; j <= 1; j++) {
        np[i] = j;
        if (i == n) {
            if (check(m)) {
                result(m);
            }
        } else {
            Try(i + 1, m);
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    init();
    for (int i = 1; i <= n; i++) {
        Try(1, i);
    }
}