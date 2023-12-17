#include<bits/stdc++.h>
using namespace std;
int n, k, m;
int x[100];
void init() {
    // k 0 bits and m 1 bits continously
    cin >> n >> k >> m;
}
bool check1bit() {
    int countDay = 0;
    int res = 0;
    int count1 = 0; 
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            count1++;
            res = max(res, count1);
            if (count1 == m) {
                countDay++;
            }
        } else  {      
            count1 = 0;
        }
    }
    return (res == m) && (countDay   == 1);
}
bool check0bit() {
    int count0 = 0;
    int res = 0;
    int countDay = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 0) {
            count0++;
            res = max(res, count0);
            if (count0 == k) {
                countDay++;
            }

        } 
         else  {
            count0 = 0;
        }
    }
    return (res == k) && (countDay == 1);
}
void result() {
    for (int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) {
        	// cout << "check0bit: " << check0bit() << ", check1bit: " << check1bit() << endl;
            // result();
            if (check0bit() == 1 && check1bit() == 1) {
                
                //  cout << "in " << endl;
                result();
            } 
        } else {
            Try(i + 1);
        }
    }
}
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    Try(1);
}
