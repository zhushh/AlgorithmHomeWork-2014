#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

struct time {
    int start;
    int end;
}arr[168];

stack<struct time> order;

int cmp(const void* a, const void* b) {
    struct time *first = (struct time *)a;
    struct time *second = (struct time *)b;
    if (first->start != second->start) {
        return first->start - second->start;
    } else {
        return first->end - second->end;
    }
}

int main() {
    int t, m;
    cin >> t;
    while (t-- > 0) {
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> arr[i].start >> arr[i].end;
        }
        qsort(arr, m, sizeof(arr[0]), cmp);
        for (int i = 0; i < m; i++) {
            if (order.empty()) {
                order.push(arr[i]);
            } else if (order.top().end < arr[i].start) {
                order.push(arr[i]);
            } else if (order.top().end > arr[i].end) {
                order.pop();
                order.push(arr[i]);
            }
        }
        int count = 0;
        while (!order.empty()) {
            count++;
            order.pop();
        }
        cout << count << endl;
    }
}

