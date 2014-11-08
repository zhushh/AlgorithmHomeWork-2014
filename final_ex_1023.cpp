#include <iostream>
#include <string>
using namespace std;

int *table[1000];

int hash(int& key, int& mod) {
    return key % mod;
}

void add(int num, int m) {
    int cur = hash(num, m);
    if (NULL == table[cur]) {
        table[cur] = new int;
        *table[cur] = num;
    } else {
        int i = 1;
        while (table[(cur + i * i) % m] != NULL) {
            i++;
        }
        table[(cur + i * i) % m] = new int;
        *table[(cur + i * i) % m] = num;
    }
}

bool query(int num, int m) {
    int cur = hash(num, m);
    if (NULL == table[cur]) {
        return false;
    } else {
        for (int i = 0; i < m; i++) {
            if (NULL != table[i] && *table[i] == num) {
                return true;
            }
        }
        return false;
    }
}

void print(int m) {
    for (int i = 0; i < m; i++) {
        if (NULL == table[i]) {
            cout << i << "#NULL" << endl;
        } else {
            cout << i << "#" << *table[i] << endl;
        }
    }
}

int main() {
    int m, num;
    string op;
    for (int i = 0; i < 1000; i++) {
        table[i] = NULL;
    }
    cin >> m;
    while (1) {
        cin >> op;
        if ("End" == op) {
            break;
        }
        if ("Add" == op) {
            cin >> num;
            add(num, m);
        } else if ("Query" == op) {
            cin >> num;
            if (query(num, m)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if ("Print" == op) {
            print(m);
        }
    }
    return 0;
}

