#include <iostream>
using namespace std;
int n;
int x[100];
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] ;
    }
    cout << endl;
}
bool isFinal( ) {
    for (int i = n - 1; i >= 0; ) {
        if (x[i] != n - k + i) {
            return false;
        }
    }
    return true;
}
void init() {
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
}
void genNext( ){
    int t = k;
    while (x[t] == (n - k + t)) {
        t--;
    }
    x[t]++;
    for (int i = t + 1; i <= k; i++) {
        x[i] = x[i - 1] + 1;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
}