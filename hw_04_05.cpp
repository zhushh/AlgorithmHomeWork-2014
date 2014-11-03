#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void permutation(int arr[], int used[], int m, int times) {
    int i, j;
    if (times == m) {
        for (i = 0; i < m; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    for (i = 0; i < m; i++) {
        if (!used[i]) {
            arr[times] = i + 1;
            used[i] = 1;
            permutation(arr, used, m, times + 1);
            used[i] = 0;
        }
    }
}

int main() {
    int t, m;
    int arr[12], used[12];
    cin >> t;
    while (t-- > 0) {
        cin >> m;
        for (int i = 0; i < m; i++) {
            used[i] = 0;
        }
        permutation(arr, used, m, 0);
    }
    return 0;
}
