#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> str;

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int t, n;
    cin >> t;
    while (t-- > 0) {
        string sub;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> sub;
            str.push_back(sub);
        }
        sort(str.begin(), str.end(), cmp);
        for (int i = 0; i < str.size(); i++) {
            cout << str[i];
        }
        cout << endl;
        str.clear();
    }
    return 0;
}
