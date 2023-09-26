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
    // int dem = 0;
    init();
    while (!isFinal()) {
        display();
        genNext();
        // cout << "New state: \n";
        // dem++;
        // if (dem == 40) {
        //     break;
        // }
    }
    display();
}
void init(){ 
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
    for (int i = n + 1; i <= s; i++) {
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
    if (a[s] == 0) {
        is0 = true;
        is1 = false;
        count0++;
    } else if (a[s] == 1) {
        is1 = true;
        is0 = false;
        count1++;
    }
    // cout << "count0: " << count0 << " ,count1:" << count1 <<endl;
    int index = -1;
    for (int i = s - 1; i >= 0; i--) {
        if (a[i] == 0) {
            count0++;
        } else if (a[i] == 1) {
            count1++;
        }
        if (is0 && a[i] == 1) {
            is1 = true;
            is0 = false;
        } else if (is1 && a[i] == 0) {
            index = i;
            // cout << "index: " << index << endl;
            break;
        }
        // cout << "count0: " << count0 << " ,count1:" << count1 <<endl;
    }
    a[index] = 1;
    count1--;
    // display();
    int current = index + 1;
    while (count0-- && current <= s) {
        a[current] = 0;
        // cout << "Dien 0 : \n";
        // display();
        current++;
    }
    int current1 = current;
    while (count1-- && current1 <= s) {
        a[current1] = 1;
        // cout << "Dien 1 : \n";
        // display();
        current1++;
    }
}