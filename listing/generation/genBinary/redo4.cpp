#include <bits/stdc++.h>
using namespace std;
int n, x[100];
void init();
void display();
void genNext();
bool isFinal();
//cu the
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
bool isFinal() {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int t = n;
    while (x[t] == 1) {
        t--;
    }
    x[t] = 1;
    for (int i = t + 1; i <= n; i++) {
        x[i] = 0;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
} 