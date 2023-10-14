#include <iostream>
using namespace std;
int n, k;
int x[] = {0, 1, 5, 6, 8, 0 , 0 ,0 , 0, 0 , 0 , 0};
void display() {
    for (int i = 1; i <= k; i++) {
        cout << x[i];
    }
    cout << endl;
}
void init() {
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
    
}
bool isFinal() {
    for (int i = 1; i <= k; i++) {
        if (x[i] != n - k + i) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int t = k;
    while (x[t] == (n - k + t)) {
        t--;
    }

    x[t]++;
    //after t index, the sequence must increase to be the smallest
    for (int i = t + 1; i <= k; i++) {
        x[i] = x[i - 1] + 1;
    }
}
int main ( ){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output_test.txt", "w", stdout);
    #endif
    n = 9;
     k = 4;
    int count = 1;
    while (count <= 4) {
        genNext();
        display();
        count++;
    }
    return 0;
}