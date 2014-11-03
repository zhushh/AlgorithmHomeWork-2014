#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s1, s2;
    cin >> n;
    while (n-- > 0) {
        cin >> s1 >> s2;
        for (int i = 0; i < s2.length(); i++) {
            s1.push_back(s1[i]);
        }
        size_t pos = s1.find(s2);
        if (pos == string::npos) {
            cout << "False" << endl;
        } else {
            cout << "True" << endl;
        }
    }
    return 0;
}

