#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> con;
bool isBracket(char c) {
    if (c == '{' || c == '}'
     || c == '(' || c == ')'
     || c == '[' || c == ']') {
        return true;
     } else {
        return false;
     }
}

void test(string& src) {
    for (size_t i = 0; i < src.size(); i++) {
        /// cout << src[i];
        if (isBracket(src[i])) {
            if (con.empty()) {
                con.push(src[i]);
            } else if ((con.top() == '{' && '}' == src[i])
                    || (con.top() == '(' && ')' == src[i])
                    || (con.top() == '[' && ']' == src[i])) {
                con.pop();
            } else {
                con.push(src[i]);
            }
        }
    }
    if (con.empty()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    while (!con.empty()) {
        con.pop();
    }
}

int main() {
    string input;
    int t;
    cin >> t;
    getline(cin, input);
    while (t-- > 0) {
        getline(cin, input);
        ///cout << "test for " << input << endl;
        test(input);
    }
    return 0;
}

