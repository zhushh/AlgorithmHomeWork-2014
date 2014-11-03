#include <iostream>
#include <stack>
using namespace std;

void cope(int, int, int, stack<int>);
int main() {
    stack<int> temp;
    int t, m, n, sum;
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n;
        cope(m, n, m, temp);
    }
    return 0;
}

void cope(int m, int n, int max, stack<int> seq) {
    if (n <= 1 || m <= 1) {
        stack<int> temp;
        n--;
        while (n-- > 0) {
            temp.push(0);
        }
        temp.push(m);
        while (!seq.empty()) {
            temp.push(seq.top());
            seq.pop();
        }
        while (!temp.empty()) {
            cout << temp.top();
            temp.pop();
        }
        cout << endl;
        return;
    }
    int min;
    min = (m%n == 0 ? 0 : 1) + m/n;
    max = m > max ? max : m;
    for (int i = max; i >= min; i--) {
        seq.push(i);
        // sum += cope(m - i, n - 1, i);
        cope(m - i, n - 1, i, seq);
        seq.pop();
    }
}

