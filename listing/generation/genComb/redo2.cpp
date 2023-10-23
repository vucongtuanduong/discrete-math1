#include <iostream>
using namespace std;
int n, k;
int x[100];
void display() {
    for (int i = 1; i <= k; i++) {
        cout << x[i] ;
    }
    cout << endl;
}
bool isFinal( ) {
    for (int i = 1; i <= k; i++) {
        if (x[i] != (n - k + i)) {
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
    cin >> n >> k;
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
}