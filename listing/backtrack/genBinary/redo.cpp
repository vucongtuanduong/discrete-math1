#include <iostream>
using namespace std;
int n;
int x[100];
void Result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            Result();
        } else {
            Try(i + 1);
        }
    } 
}
int main ( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    Try(1);
    return 0;
}
