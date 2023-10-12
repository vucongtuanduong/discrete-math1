#include <iostream>

using namespace std;
int n, x[100];
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = i;
    }

}
bool isFinal() {
    for (int i = 1; i <= n; i++) {
        if (x[i] != (n - i + 1)) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int i = n;
    while(x[i] < x[i - 1]) {
        i--;
    }
    for (int j = n; j >= i; j--) {
        if (x[j] > x[i - 1]) {
            swap(x[j], x[i - 1]);
            break;
        }
    }
    for (int j = i; j < n; j++) {
        for (int k = j + 1; k <= n; k++) {
            if (x[j] > x[k]) {
                swap(x[j], x[k]);
            }
        }
    }
}
int main ( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    init();
    while(!isFinal()) {
        display();
        genNext();
    }
    display();
    return 0;
}