/***********************************************************************
 *  > File Name: final_ex_1021.cpp
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 05 Nov 2014 11:49:54 AM CST
***********************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

#define HASHSIZE 13

struct Node {
    int value;
    struct Node *next;
};
struct Node *table[HASHSIZE];

int hash(int key) {
    return key % HASHSIZE;
}
bool insertNode(int& value) {
    struct Node *ptr = table[hash(value)];
    struct Node *new_node = new struct Node;
    if (NULL == new_node) return false;
    new_node->value = value;
    new_node->next = NULL;
    if (NULL == ptr) {
        table[hash(value)] = new_node;
        return true;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return true;
}
void clear() {
    struct Node *temp;
    for (int i = 0; i < HASHSIZE; i++) {
        temp = table[i];
        while (NULL != temp) {
            table[i] = temp->next;
            delete temp;
            temp = table[i];
        }
    }
}

int main() {
    int i, n, num;
    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < HASHSIZE; i++) {
            table[i] = NULL;
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &num);
            insertNode(num);
        }
        struct Node *ptr;
        for (i = 0; i < HASHSIZE; i++) {
            ptr = table[i];
            printf("%d#", i);
            while (NULL != ptr) {
                printf("%d", ptr->value);
                ptr = ptr->next;
                if (NULL != ptr) printf(" ");
            }
            if (ptr != table[i]) {
                printf("\n");
            } else {
                printf("NULL\n");
            }
        }
        clear();
    }
    return 0;
}

