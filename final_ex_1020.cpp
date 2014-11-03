#include <stdio.h>

void mergeSort(int *a, int n) {
    int i, j, sumTime, ok;
    sumTime = 0;
    for (i = 0; i < n - 1; i++) {
        ok = 0;
        for (j = i + 1; j > 0 && j < n; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            } else if (j == i + 1) {
                ok = 1;
            }
        }
        if (!ok) {
            sumTime += 5;
        }
    }
    printf("%d\n", sumTime);
}

int main() {
    int num[10005];
    int n, i, t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        mergeSort(num, n);
    }
    return 0;
}

