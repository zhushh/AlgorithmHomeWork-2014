#include <iostream>
using namespace std;

int main() {
    int t, sum, num;
    cin >> t;
    while (t-- > 0) {
        int product[3], product_id;
        product[0] = product[1] = product[2] = -1;
        cin >> sum;
        for (int i = 0; i < sum; i++) {
            cin >> product_id >> num;
            if (product[product_id - 1] < num) {
                product[product_id - 1] = num;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (product[i] > 0) {
                cout << i + 1 << " " << product[i] << endl;
            }
        }
    }
    return 0;
}

