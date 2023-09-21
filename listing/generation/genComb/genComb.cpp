#include <iostream>
using namespace std;
//initialize variables
int n, k;
int x[100];
void init();
bool isFinal();
void genNext();
void display();
int main (){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
	cin >> n >> k;
    
    init();
	while (!isFinal()) {
        display();
        genNext();
    }
	display();
}
void init() {

    for (int i = 1; i <= k; i++) {
		x[i] = i;
	}
}
bool isFinal() {
    for (int i = 1; i <= k; i++) {
        if (x[i] != (n - k + i)) {
            return false;
        }
    }
    return true;
}
void genNext() {
    int m = k;
    while (x[m] == (n - k + m)) {
        m--;
    }
    x[m]++;
    for (int i = m + 1; i <= k; i++) {
        x[i] = x[i - 1] + 1;
    }

}
void display() {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}