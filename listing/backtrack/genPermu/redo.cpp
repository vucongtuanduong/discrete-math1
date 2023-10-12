#include <iostream>
using namespace std;
int n;
int x[100];
bool unused[100];
void Result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                Result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
        }
        
    }
}
int main ( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        unused[i] = true;
    }
    Try(1);
    return 0;
}