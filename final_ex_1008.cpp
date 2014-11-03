#include <iostream>
#include <stack>
using namespace std;

stack<int> order;

int main()
/* pre: a 10 numbers sequece
  post: output Yes or No
 using: using a stack to try to construct the sequence, number start
        from 1 to 10, the stack is empty if the sequence can be constructed,
        otherwise, the sequence can not be constructed.
 */
{
    int t, num[11];
    cin >> t;
    while (t-- > 0) {
        for (int i = 1; i < 11; i++) {
            cin >> num[i];
        }
        int i, j;
        for (i = 1, j = 1; i < 11;) {
            if (num[j] == i) {  // shoot the number i
                i++;
                j++;
            } else if (order.empty()) {
                order.push(i++);
            } else if (num[j] == order.top()) {     // shoot the top of the stack
                order.pop();
                j++;
            } else {    // do not shoot, just push
                order.push(i++);
            }
        }
        while (!order.empty() && order.top() == num[j]) {
            order.pop();
            j++;
        }
        cout << (order.empty() ? "Yes" : "No");
        cout << endl;
        while (!order.empty()) {    // clear for the next case
            order.pop();
        }
    }
    return 0;
}

