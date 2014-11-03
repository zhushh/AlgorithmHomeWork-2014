#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

void division(stack<int> seq, int m, int max) {
    if (m < 1 || max < 1) {
        return;
    }
    if (m == 1 || max >= m) {   // print expression
        stack<int> temp;
        if (m != 0)
            temp.push(m);
        while (!seq.empty()) {
            temp.push(seq.top());
            seq.pop();
        }
        cout << temp.top();
        seq.push(temp.top());
        temp.pop();
        while (!temp.empty()) {
            cout << '+' << temp.top();
            seq.push(temp.top());
            temp.pop();
        }
        cout << endl;
        seq.pop();
    }
    int i;
    max = max > m ? m : max;
    for (i = max; i > 0; i--) {
        seq.push(i);
        division(seq, m - i, i);
        seq.pop();
    }
}

int main() {
    stack<int> q;
    int m, n;
    cin >> n;
    while (n-- > 0) {
        cin >> m;
        cout << m << endl;
        division(q, m, m - 1);
    }
    return 0;
}

