#include <iostream>
#include <map>
using namespace std;

int hash(int num, int m) {
    return num % m;
}
int main() {
    map<int, int> t;
    int m, n, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (t.find(hash(num, m)) == t.end()) {
            t[hash(num, m)] = num;
        } else {
            int temp = num++;
            while (t.find(hash(num, m)) != t.end()) num++;
            t[hash(num, m)] = temp;
        }
    }
    for (int i = 0; i < m; i++) {
        if (t.find(i) != t.end()) {
            cout << i << "#" << t[i] << endl;
        } else {
            cout << i << "#" << "NULL" << endl;
        }
    }
    return 0;
}
