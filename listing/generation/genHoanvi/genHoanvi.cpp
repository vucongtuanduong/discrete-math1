#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
//initialize variables
int n;
int x[100];
void init();
bool isFinal();
void genNext();
void display();
int main (){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
	cin >> n;
    // int count = 0;
    init();
	while (!isFinal()) {
        display();
        genNext();
        // count++;
        // if (count == 20) {
        //     break;
        // }
    }
	display();
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
    int t = n;
    int temp = x[t];
    t--;
    while (x[t] > temp) {
        temp = x[t];
        t--;
    }
    // cout << "index to swap: " << t << endl;
    int max_index = t + 1;
    int min_sub = x[t + 1] - x[t];
    for (int i = t + 2; i <= n; i++) {
        int temp = x[i] - x[t];
        if (temp > 0 && temp < min_sub) {
            max_index = i;
        }
        // if (x[i] == (x[t] + 1)) {
        //     max_index = i;
        // }
    }
    // cout << "max_index: " << max_index << endl;
    swap(x[t], x[max_index]);
    vector<int> v;
    stack<int> st;
    int current = 0;
    for (int i = t + 1; i <= n; i++) {
   	    v.push_back(x[i]);
        st.push(x[i]);
	}
	int m = v.size() - 1;
	for (int i = t + 1; i <= n; i++) {
		x[i] = st.top();
        st.pop();
	}

}
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
//    for (int i = n; i >= t + 1; i--) {
//        cout << x[i] << " ";
//    }
    cout << endl;
}