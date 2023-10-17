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
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            return false;
        }
    }
    return true;
}
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
void genNext( ){
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