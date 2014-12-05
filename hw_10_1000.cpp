/*************************************************************************
	> File Name: hw_10_1000.cpp
	> Author: zhushh
	> Mail: 
	> Created Time: Fri 05 Dec 2014 04:41:27 PM CST
*************************************************************************/

#include <cstdio>
#include <iomanip>

#define MAX 10001

int m, n;
double sum;
char *table[MAX];

void init() {
    sum = 0;
    for (int i = 0; i < m; i++) {
        table[i] = NULL;
    }
}

int nameValue(char * name) {
    int value = 0;
    while (*name != '\0') {
        value += (*name++ - 'a' + 1);
    }
    return value;
}

int hash(int key) {
    return key % m;
}

void insert_hash(int key, char *name) {
    int i;
    sum++;
    for (i = key; table[i % m] != NULL; i++) sum++;
    table[i % m] = name;
}

void print() {
    for (int i = 0; i < m; i++) {
        printf("%d:", i);
        if (table[i] != NULL) {
            printf("%s\n", table[i]);
        } else {
            printf("NULL\n");
        }
    }
    printf("%.3lf\n", sum / n);
}

void free_new() {
    for (int i = 0; i < m; i++) {
        if (table[i] != NULL) {
            delete table[i];
            table[i] = NULL;
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        int index;
        for (int i = 0; i < n; i++) {
            char * name = new char[11];
            scanf("%s", name);
            index = hash(nameValue(name));
            insert_hash(index, name);
        }
        print();
        free_new();
    }
    return 0;
}

