/*************************************************************************
	> File Name: hw_10_1003.cpp
	> Author: zhushh
	> Mail: 
	> Created Time: Fri 05 Dec 2014 06:20:33 PM CST
*************************************************************************/

#include <cstdio>

#define MAX 302
#define NUM 12
int numOfStudents, numOfProblem;
int table[MAX][NUM] = {0};

int main() {
    int id, pro_num;
    scanf("%d%d", &numOfStudents, &numOfProblem);
    while (scanf("%d%d", &id, &pro_num) != EOF) {
        table[id][pro_num]++;
    }
    for (int i = 1; i < numOfStudents + 1; ++i) {
        for (int j = 1; j < numOfProblem; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("%d\n", table[i][numOfProblem]);
    }
    return 0;
}

