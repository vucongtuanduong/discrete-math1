#include <iostream>
using namespace std;
int n;
int x[100];
bool unused[100], xuoi[100], nguoc[100];
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] ;
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            x[i] = j;
            unused[j] = false;
            xuoi[i - j + n] = false;
            nguoc[i + j - 1] = false;
            if (i == n) {
                result();
            } else {
                Try(i + 1);
            }
            unused[j] = true;
            xuoi[i - j + n] = true;
            nguoc[i + j - 1] = true;
        }
    }
}
int main () {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        unused[i] = true;
        xuoi[i] = true;
        nguoc[i] = true;
    }
    Try(1);
}