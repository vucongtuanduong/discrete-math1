#include <iostream>
#include <cstring>
using namespace std;
int n;
int x[100];
bool unused[100] = {};
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void backTrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (unused[j]) {
            x[i] = j;
            unused[j] = false;
            if (i == n) {
                result();
            } else {
                backTrack(i + 1);
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
    memset(unused, true, sizeof(unused));
    cin >> n;
    backTrack(1);
    return 0;
}