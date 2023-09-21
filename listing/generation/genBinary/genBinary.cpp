#include <iostream>
using namespace std;
void init(int x[], int n);
bool isFinal(int x[], int n);
void genNext(int x[], int n);
void display(int x[], int n);
int main (){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
	cin >> n;
    int x[100];
    init(x, n);
	while (!isFinal(x, n)) {
        display(x, n);
        genNext(x, n);
    }
	display(x, n);
}
void init(int x[], int n) {
//	int x[100];
    for (int i = 1; i <= n; i++) {
		x[i] = 0;
	}
}
bool isFinal(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            return false;
        }
    }
    return true;
}
void genNext(int x[], int n) {
    int index = n;
    while (x[index] == 1) {
    	x[index] = 0;
    	index--;
	}
	x[index] = 1;
//    for (int i = n; i >= 1; i--) {
//        if (x[i] == 0) {
//            index = i;
//            break;
//        }
//    }
//    for (int i = index; i <= n; i++) {
//        x[i] = 0;
//    }
}
void display(int x[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}