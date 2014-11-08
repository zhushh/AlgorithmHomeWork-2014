#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binarySearch(const vector<T> table, int bot, int top, const T &x)
{
    bool increasing = false;
    if (table[bot] <= table[top]) {
        increasing = true;
    }
    if (bot > top) {
        int temp = bot; bot = top; top = bot;
    }
    int mid = bot + (top - bot) / 2;
    while (bot <= top) {
        if (table[mid] == x) {
            while (mid < top && table[mid + 1] == table[mid]) {
                mid++;
            }
            return mid;
        } else if (increasing && table[mid] < x) {
            bot = mid + 1;
        } else if (increasing) {
            top = mid - 1;
        } else if (table[mid] < x) {
            top = mid - 1;
        } else {
            bot = mid + 1;
        }
        mid = bot + (top - bot) / 2;
    }
    return -1;
}

int main() {
    int a[] = {
        1, 1, 1, 1, 1, 1, 1
    };
    vector<int> v(a, a +7);
    cout << binarySearch(v, 0, v.size() - 1, 1) << endl;
    cout << binarySearch(v, 0, v.size() - 1, 2) << endl;
    return 0;
}

