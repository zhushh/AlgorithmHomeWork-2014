#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return (a < b);
}

int main() {
    int n;
    int arr[20];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        (i < n - 1 ? cout << " " : cout << '\n');
    }
    if (n % 2 == 1) {
        cout << arr[n/2];
    } else {
        cout << (arr[n/2] + arr[n/2 - 1]) / 2;
    }
    return 0;
}

