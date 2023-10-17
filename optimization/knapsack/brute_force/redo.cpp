#include <iostream>
using namespace std;
int n;
int b;//max weight
int fopt;//max value you can loot
int x[100];
int xopt[100];
int a[100];//weight
int c[100];//value
void input() {
    //enter n
    cin >> n;
    //enter b
    cin >> b;
    //enter a[i]
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //enter c[i]
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
}
bool checkWeight() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] * x[i];
        if (sum > b) {
            return false;
        }
    }
    return true;
}
int calcValue() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += c[i] * x[i];
    }
    return sum;
}
void update() {
    int totalValue = calcValue();
    if (totalValue > fopt && checkWeight()) {
        fopt = totalValue;
        for (int i = 1; i <= n; i++) {
            xopt[i] = x[i];
        }
    }
}
void printResult() {
    cout << "The best combination is: ";
    for (int i = 1; i <= n; i++) {
        cout << xopt[i] ;
    }
    cout << "\nTotal value: " << fopt << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
            update();
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    input();
    Try(1);
    printResult();
}