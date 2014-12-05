/*************************************************************************
	> File Name: hw_10_1002.cpp
	> Author: zhushh
	> Mail: 
	> Created Time: Fri 05 Dec 2014 05:35:02 PM CST
*************************************************************************/

#include <cstdio>
#include <vector>
using std::vector;

int m, n, t;
double sum;
std::vector< vector<int> > table(11);

int hash(int key) {
    return key % t;
}

void insert_hash(int key, int value) {
    table[key].push_back(value);
    sum += table[key].size();
}

void clear() {
    for (int i = 0; i < t; i++) {
        table[i].clear();
    }
}

void print() {
    for (int i = 0; i < t; i++) {
        for (int j = table[i].size() - 1; j >= 0; --j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("%.3lf\n", sum / n);
}

int main() {
    while (scanf("%d%d", &n, &t) != EOF) {
        int num;
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            insert_hash(hash(num), num);
        }
        print();
        clear();
    }
    return 0;
}

