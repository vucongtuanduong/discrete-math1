#include<bits/stdc++.h>
using namespace std;
int n, k;
int x[100];
int np[100];
void init() {
    cin >> n >> k;
}
bool check() {
    int count1 = 0;
    bool is1 = false;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (np[i] == 1 && is1 == false) {
            count1 ++;
            is1 = true;
            res = max(count1, res);
        } else if (np[i] == 1 && is1 == true) {
            count1++; 
            res = max(count1, res);
        } else if (np[i] == 0) {
            count1 = 0;
            res = max(count1, res);
        }
    }
    if (res == k) {
        return true;
    } else {
        return false;
    }

}
void result() {
    for (int i = 1; i <= n; i++) {
        if (np[i] == 1) {
            cout << "B";
        } else {
            cout << "A";
        }
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        np[i] = j;
        if (i == n) {
            if (check()) {
                result();
            } 
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    init();
    Try(1);
}
