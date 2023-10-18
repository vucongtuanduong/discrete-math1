#include <iostream>
#include <stack>
using namespace std;
int n;
int x[100];
void display() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
bool isFinal( ) {
    for (int i = 1; i <= n; i++) {
        if (x[i] != (n - i + 1)) {
            return false;
        }
    }
    return true;
}
void init() {
    for (int i = 1; i <= n; i++) {
        x[i] = i;
    }
}
void genNext( ){
    int t = n;
    int temp = x[n];
    t--;
    while (x[t] > temp) {
        temp = x[t];
        t--;
    }
    int max_index = t + 1;
    int min_sub = x[t + 1] - x[t];
    for (int i = t + 2;  i <= n; i++) {
        int sub = x[i] - x[t];
        if (sub > 0 && sub < min_sub) {
            max_index = i;
        }
    }
    swap(x[t], x[max_index]);
    stack<int> st;

    for (int i = t + 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[j] < x[i]) {
                swap(x[j], x[i]);
            }
        }
	}
	// for (int i = t + 1; i <= n; i++) {
	// 	x[i] = st.top();
    //     st.pop();
	// }

}
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    init();
    while (!isFinal()) {
        display();
        genNext();
    }
    display();
}