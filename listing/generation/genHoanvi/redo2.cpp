#include <iostream>
using namespace std;
int n;
int x[100];
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
bool isFinal( ) {
    for (int i = 1; i <= n; i++) {
        if (x[i] != (n - i + 1)) {
            return false;
        }
    }
    return true;
}
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = i;
    }
}
void genNext( ){
    // 987
    int t = n - 1;
    while (x[t] > x[t + 1]) {
        t--;
    }
    int k = n;
    while (x[t] > x[k]) {
        k--;
    }
    swap(x[k], x[t]);
    int left = t + 1;
    int right = n;
    while (left <= right) {
        swap(x[left], x[right]);
        left ++;
        right--;
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