#include <bits/stdc++.h>
using namespace std;
int x[100], n;
void init();
void display();
bool isFinal();
void genNext();
//cu the
void display() {
    for (int i = 1;i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = i;
    }
}
bool isFinal() {
    for (int i = 1; i <= n - 1; i++) {
        if (x[i] < x[i + 1]) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int t = n - 1;
    while (x[t] > x[t + 1]) {
        t--;
    }
    int k = n;
    while (x[k]< x[t]) {
        k--;
    }
    swap(x[t], x[k]);
    int l = t + 1, r = n;
    while (l <= r) {
        swap(x[l], x[r]);
        l++;
        r--;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    init();
    while (!isFinal()) {
        display();
        genNext();

    }
    display();
}