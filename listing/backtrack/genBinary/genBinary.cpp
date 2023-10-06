#include <iostream>
using namespace std;
int n;
int x[100];
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void backTrack(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            result();
        } else {
            backTrack(i + 1);
        }
    }
}

int main ( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    backTrack(1);
    return 0;
}