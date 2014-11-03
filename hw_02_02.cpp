#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> order;
queue<int> temp;
stack<int> reverse;

int main() {
    int t, num;
    cin >> t;
    while (t-- > 0) {
        cin >> num;
        for (int i = num; i > 0; i--) {
            while (!order.empty()) {
                temp.push(order.front());
                order.pop();
            }
            order.push(i);
            while (!temp.empty()) {
                order.push(temp.front());
                temp.pop();
            }
            for (int j = 0; j < i; j++) {
                order.push(order.front());
                order.pop();
            }
        }
        while (!order.empty()) {
            reverse.push(order.front());
            order.pop();
        }
        while (!reverse.empty()) {
            cout << reverse.top() << " ";
            reverse.pop();
        }
        cout << endl;
    }
    return 0;
}

