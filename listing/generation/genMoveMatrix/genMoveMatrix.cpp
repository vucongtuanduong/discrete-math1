#include <iostream>
using namespace std;
int n, m, s;
int a[100];
//0 is up and 1 is right

void init();
bool isFinal();
void display();
void genNext();
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    s = n + m;
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
}
void init(){ 
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
    for (int i = n + 1; i <= m; i++) {
        a[i] = 1;
    }
}
void display() {
    for (int i = 1; i <= s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool isFinal() {
    for (int i = 1; i <= m; i++) {
        if (a[i] == 0) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int count0 = 0, count1 = 0;
    bool is1 = true;
    bool is0 = false;
}