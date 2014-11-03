#include <iostream>
using namespace std;

int main() {
    int t, m;
    int a[3];
    cin >> t;
    while (t-- > 0) {
        int index, num;
        cin >> m;
        a[0] = a[1] = a[2] = 0;
        while (m-- > 0) {
            cin >> index >> num;
            if (a[index - 1] < num) {
                a[index - 1] = num;
            }
        }
        for (index = 0; index < 3; index++) {
            if (a[index] != 0) {
                cout << index + 1 << ' ' << a[index] << endl;
            }
        }
    }
    return 0;
}

