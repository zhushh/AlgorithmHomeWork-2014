#include <iostream>
using namespace std;

int main() {
    int n, money;
    cin >> n;
    while (n-- > 0) {
        cin >> money;
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        a = money / 100;
        money -= (a * 100);
        b = money / 50;
        money -= (b * 50);
        c = money / 20;
        money -= (c * 20);
        d = money / 10;
        money -= (d * 10);
        e = money / 5;
        money -= (e * 5);
        f = money;
        cout << a + b + c + d + e + f << endl;
    }
    return 0;
}

