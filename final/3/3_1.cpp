#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int x[100];
int a[100];
bool unused[100];
map<int,int> dadung;
void init() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    cin >> n >> k;
    sort(x + 1,x + m + 1);
    cout << "x: ";
    for (int i = 1; i <= m; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < 100; i++) {
        unused[i] = true;
    }
}
void result() {
    for (int i = 1; i <= k; i++) {
        if (dadung[a[i]] == 1) {
            return;
        }
        cout << a[i];
        
        dadung[a[i]]++;
    }
    cout << endl;
}
bool check() {
    int res = 0;
    for (int i = 1; i <= k; i++) {
        res += a[i];
    }
    return res == n;
}
void Try(int i) {

    for (int j = 1; j <= m; j++) {
        if (unused[x[j]]) {

        
            a[i] = x[j];
            unused[x[j]]= false;
            if (i == k) {
                if (check()) {
                    result();
                }
            } else {
                Try(i + 1);
            }
            unused[x[j]] = true;
        }
        
        
        
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    init();

    Try(1);
}