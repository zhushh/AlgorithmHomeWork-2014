#include <iostream>
using namespace std;

int cope(int, int, int);
int main() {
    int t, m, n, sum;
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n;
        sum = cope(m, n, m);
        cout << sum << "\n";
    }
    return 0;
}

int cope(int m, int n, int max) {
    if (n <= 1 || m <= 1) {
        return 1;
    }
    int min, sum;
    min = (m%n == 0 ? 0 : 1) + m/n;
    max = m > max ? max : m;
    sum = 0;
    for (int i = max; i >= min; i--) {
        sum += cope(m - i, n - 1, i);
    }
    return sum;
}

