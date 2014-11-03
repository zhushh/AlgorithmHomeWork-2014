#include <iostream>
using namespace std;
#define TABLESIZE 15

struct Node {
    int value;
    struct Node* next;
};

struct Node *table[TABLESIZE];

int hash(int key) {
    return key % 13;
}
bool insertItem(int hashValue, int value) {
    struct Node *ptr = table[hashValue];
    struct Node *temp = new struct Node;
    temp->value = value;
    temp->next = NULL;
    if (ptr == NULL) {
        table[hashValue] = temp;
        return true;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return true;
}
void print() {
    struct Node *ptr;
    for (int i = 0; i < 13; i++) {
        ptr = table[i];
        cout << i << '#';
        while (ptr != NULL) {
            cout << ptr->value;
            if (ptr->next != NULL) {
                cout << ' ';
            }
            ptr = ptr->next;
        }
        if (ptr == table[i]) {
            cout << "NULL";
        }
        cout << endl;
    }
}

int main() {
    int t, num;
    while (cin >> t && t != 0) {
        for (int i = 0; i < TABLESIZE; i++) {
            table[i] = NULL;
        }
        for (int i = 0; i < t; i++) {
            cin >> num;
            insertItem(hash(num), num);
        }
        print();
    }
    return 0;
}

