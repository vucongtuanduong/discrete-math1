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
    int res = 0;
    int countDay = 0;
    for (int i = 1; i <= n; i++) {
        if (np[i] == 1) {
            count1 ++;
            res = max(count1, res);
            if(count1 == k) {
                countDay++;
            }
        } else{
            count1 = 0;
            res = max(count1, res);
        }
    }
    return (res == k) && (countDay == 1);

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
    freopen("output.txt", "w", stdout);
    init();
    Try(1);
}
