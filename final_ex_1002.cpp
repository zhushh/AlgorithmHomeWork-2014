#include <stdio.h>

int a[1010][1010];

int main() 
/* 杨氏矩阵快速查找元素 */
{
    int t, m, n, num, i, j, k;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            int found = 0;
            scanf("%d", &num);
            j = 0;
            k = n - 1;
            while (n > j && k >= 0) {
                if (num == a[j][k]) {
                    found = 1;
                    break;
                } else if (num < a[j][k]) {
                    k--;
                } else {
                    j++;
                }
            }
            if (found) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }
    return 0;
}

