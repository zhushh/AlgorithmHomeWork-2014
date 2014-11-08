#include <iostream>
using namespace std;

bool isValid(int test, int num) {
    int i = 0, temp = test;
    int sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    if (sum + test == num) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t, num;
    cin >> t;
    while (t-- > 0) {
        cin >> num;
        int m = num, count = 0;
        while (m > 0) {
            m /= 10;
            count++;
        }
        bool OK = false;
        for (int i = num - count*10; i <= num; i++) {
            if (i > 0 && isValid(i, num)) {
                OK = true;
                cout << i << endl;
                break;
            }
        }
        if (!OK) {
            cout << 0 << endl;
        }
    }
    return 0;
}
