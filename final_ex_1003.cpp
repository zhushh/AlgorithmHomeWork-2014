#include <iostream>
using namespace std;

int a[1005];

void cope(int);
int main() {
    int t, n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cope(n);
    }
    return 0;
}

void output(int n) {
    if (n <= 0) return;
    cout << a[0];
    for (int i = 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}
void cope(int n) {
    int min, index;
    for (int i = 0; i < n - 1; i++) {
        min = a[i];
        index = i;
        for (int j = i + 1; j < n; j++) {
            if (min > a[j]) {
                min = a[j];
                index = j;
            }
        }
        min = a[i];
        a[i] = a[index];
        a[index] = min;
        output(n);
    }
}

