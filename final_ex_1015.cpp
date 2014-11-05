#include <iostream>
using namespace std;

int main() {
    int t, i, m, n, num, max;
    cin >> t;   // test case
    while (t-- > 0) {
        cin >> m >> n;      // friends' number and homes' number
        cin >> max;
        for (i = 1; i < m; i++) {
            cin >> num;
            if (num > max) {
                max = num;
            }
        }
        int count = 0;
        for (i = 0; i < n; i++) {
            cin >> num;
            if (num != max) {
                count++;
            } else {
                break;
            }
        }
        while (++i < n) {
            cin >> num;
        }
        cout << 50 * count << endl;  // count the small path
    }
    return 0;
}

