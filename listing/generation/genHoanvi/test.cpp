#include <iostream>

using namespace std;
int n, x[] = {0, 1,3,9,5,8,7,6,4,2};
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
    freopen("output1.txt", "w", stdout);
    #endif
    n = 9;
    int count = 0;
    while(count <= 4) {
        genNext();
        display();
        count++;
    }

    return 0;
}