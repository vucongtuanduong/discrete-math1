#include <iostream>
using namespace std;
int n;
int x[100];
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
bool isFinal() {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            return false;
        }
    }
    return true;
}
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void genNext() {
    int i = n;
    while(x[i] == 1) {
        x[i] = 0;
        i--;
    }
    x[i] = 1;
}
int main ( ){
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

    return 0;
}