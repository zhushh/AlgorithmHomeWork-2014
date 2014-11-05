#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define in true
#define out false
stack<char> s;
std::vector<bool> ans;

int main() {
    int num;
    size_t i, j;
    string inOrder, outOrder;
    while (scanf("%d", &num) != EOF) {
        cin >> inOrder >> outOrder;
        for (i = 0, j = 0; i < outOrder.length();) {
            if (j < inOrder.length() && outOrder[i] == inOrder[j]) {
                ans.push_back(in);
                ans.push_back(out);
                j++;
                i++;
            } else if (s.empty()) {
                ans.push_back(in);
                s.push(inOrder[j]);
                j++;
            } else if (s.top() == outOrder[i]) {
                ans.push_back(out);
                s.pop();
                i++;
            } else if (j < inOrder.length()) {
                ans.push_back(in);
                s.push(inOrder[j]);
                j++;
            } else if (j == inOrder.length() && s.top() != outOrder[i]) {
                break;
            }
        }
        s.empty() ? cout << "Yes." << endl : cout << "No." << endl;
        i = 0;
        while (s.empty() && i < ans.size()) {
            if (ans[i++] == in) {
                cout << "in" << endl;
            } else {
                cout << "out" << endl;
            }
        }
        ans.clear();
        while (!s.empty()) { s.pop(); }
        cout << "FINISH" << endl;
    }
    return 0;
}
