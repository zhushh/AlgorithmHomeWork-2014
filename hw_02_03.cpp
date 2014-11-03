#include <iostream>
#include <stack>
using std::cin;
using std::cout;
using std::endl;

int cop(std::stack<int> left, std::stack<int> right) {
    if (left.empty()) {
        return 1;
    }
    int count = 0;
    int top;
    if (!left.empty()) {        // first case
        top = left.top();
        left.pop();
        count += cop(left, right);
        left.push(top);
    }
    if (!right.empty()) {       // second case
        top = right.top();
        right.pop();
        count += cop(left, right);
        right.push(top);
    }
    if (left.size() > 1) {      // third case
        right.push(left.top());
        left.pop();
        right.push(left.top());
        left.pop();
        count += cop(left, right);
    }
    return count;
}

int main() {
    std::stack<int> left, right;
    int t, num;
    cin >> t;
    while (t-- > 0) {
        cin >> num;
        int sum = 0;
        for (int i = 1; i < num + 1; i++) {
            for (int j = 1; j < i; j++) {
                left.push(j);
            }
            for (int k = i + 1; k < num + 1; k++) {
                right.push(k);
            }
            sum += cop(left, right);
            while (!left.empty()) {
                left.pop();
            }
            while (!right.empty()) {
                right.pop();
            }
        }
        cout << sum << endl;
    }
    return 0;
}
