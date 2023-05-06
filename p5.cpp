#include <iostream>
using namespace std;

int main() {
    int n, d[30], d1 = 0, r = 1;
    int a[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    cin >> n;
    int n1[n];
    for (int i = 0; i < n; i++) {
        cin >> n1[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 15; j++) {
            if (n1[i] % a[j] == 0) {
                d[d1] = a[j];
                d1++;
                n1[i] /= a[j];
                for (int k = i+1; k < n; k++) {
                    if (n1[k] % a[j] == 0) {
                        n1[k] /= a[j];
                    }
                }
                if (n1[i] % a[j] == 0) {
                    j--;
                }
            }
        }
    }
    for (int i = 0; i < d1; i++) {
        r *= d[i];
    }
    cout << r << endl;
}
