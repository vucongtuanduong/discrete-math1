#include<bits/stdc++.h>
using namespace std;
int n, m;
int s;
int x[100];
int np[100];
void init() {
    cin >> n >> m;
    s = n + m;
}
bool check() {
    int count1 = 0;
    int count0 = 0;
    for(int i = 1; i <= s; i++) {
        if (x[i] == 1) {
            count1++;
        } else if (x[i] == 0) {
            count0++;
        }
    }
    return (count0 == n && count1 == m);

}
void result() {
    for (int i = 1; i <= s; i++) {
        cout << x[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == s) {
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
