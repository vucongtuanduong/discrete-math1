#include <iostream>
using namespace std;
void init(int *a, int n, int k);
void genNext(int *a, int n, int k);
bool isFinal(int *a, int n, int k);
void display(int *a, int n, int k);
bool isValid(int *a, int n, int k);
void copyArray(int *dest, int *ori, int n) ;
bool isFinal1(int *a, int n, int k);
int main () {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
    int n, k;
    cin >> n >> k;
    int *a = new int[100];
    int dem  = 0;
    init(a, n, k);
    while (!isFinal1(a, n ,k)) {
        display(a, n, k);
        genNext(a, n, k);
        dem++;
        if (dem == 2000) {
            break;
        }
    }
    display(a, n, k);

    // cout << n << " " << k << endl;
    // 1 1 1 0 1 1 0 
    // a[1] = a[2]= a[3] = 1;
    // a[4] = 0;
    // a[5] = a[6] = a[7] = 1;
    // a[8] = 0;
    // a[9] = a[10]= a[11] = 1;
    // a[12] = 0;
    // a[1] = a[2]= a[3] = 1;
    // a[4] = 0;
    // a[5] = a[6] = 1;
    // a[7] = 0;
    // cout << isFinal(a, n, k);
}
void init(int *a, int n, int k){
    int t = n;
    int e = k;
    while (e--) {
        a[t] = 1;
        t--;
    }
    for (int i = 1; i <= n - k; i++) {
        a[i] = 0;
    }
}
bool isFinal(int *a, int n, int k) {
    for (int i = 1; i <= k; i++) {
        if (a[i] == 0) {
            return false;
        }
    }

    bool is0 = true;
    bool is1 = false;
    bool ok = true;
    int m = k + 1;
    // cout << m << endl;
    while (m <= n) {
        if (a[m] == 0) {
            is0 = true;
            is1 = false;
        } else {
            return false;
        }
        int s = m + k;
        int r = min(s, n);
        int count1 = 0;
        for (int j = m + 1; j <= r; j++) {
            if (a[j] == 1) {
                count1++;
            }
            if (is0 && a[j] == 0) {
                return false;
            } else if (is1 && a[j] == 0 && count1 != k - 1) {
                return false;
            } else if (is0 && a[j] == 1) {
                is0 = false;
                is1 = true;
            } else if (is1 && a[j] == 0 && count1 == k - 1) {
                // return false;
                // return true;
                is0 = true;
                is1 = false;
            }
            if (count1 == k) {
                return false;
            }
        }
        m += (k + 1);
    }
    return true;
}
void display(int *a, int n, int k) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void genNext(int *a, int n, int k) {
    int t = n;
    int *b = new int[100];
    copyArray(b, a, n);
    while (t >= 1) {
        if (a[t] == 0) {
            a[t] = 1;
            if (isValid(a, n, k)) {
                return;
            }
        } else {
            a[t] = 0;
            t--;
        }
    }
    // if (isValid(a, n, k)) {
    //     return;
    // }
    copyArray(a, b, n);
    // display(a, n, k);
    int index = -1;
    for (int j = 1; j <= n; j++) {
        if (a[j] == 1) {
            index = j - 1;
            // cout << "index: " << index << endl;
            break;
        }
    }
    int countK = k;
    while (countK--) {
        a[index] = 1;
        // cout << "a[" << index << "] = " << a[index] << endl;
        index++;
    }
    // index++;
    while (index <= n) {
        a[index] = 0;
        // cout << "a[" << index << "] = " << a[index] << endl;
        index++;
    }
}
bool isValid(int *a, int n, int k) {
    int count = 0;
    int countK = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            count++;
            if (count > k) {
                return false;
            } 
        } else {
            if (count == k) {
                countK++;
                count = 0;
            }
            count = 0;//reset if a[i] == 0
        }
        
    }
    if (count == k) {
        countK++;
    }
    return countK == 1;
}
void copyArray(int *dest, int *ori, int n) {
    for (int i = 1; i <= n; i++) {
        dest[i] = ori[i];
    }
}
bool isFinal1(int *a, int n, int k)  {
    int *b = new int[100];
    for (int i = 1; i <= k; i++) {
        b[i] = 1;
    }
    int t = k + 1;
    while (t <= n) {
        b[t] = 0;
        int m = t + k - 1;
        int r = min(m, n);
        for (int j = t + 1; j <= r; j++) {
            b[j] = 1;
        }
        t += k;
    }
    // cout << "b: \n";
    // display(b, n, k);
    for (int i = 1; i <= n; i++) {
    	if (a[i] != b[i]) {
    		return false;
		}
	}
	return true;
}