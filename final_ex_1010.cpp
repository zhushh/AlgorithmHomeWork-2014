#include <stdio.h>

void mergeSort(int *a, int n) {
    int i, j, ok = 1;
    for (i = 0; i < n; i++) {
        if (ok) {
            for (j = 0; j < n; j++) {
                printf("%d ", a[j]);
            }
            printf("\n");
        }
        ok = 0;
        for (j = i + 1; j > 0 && j < n; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                ok = 1;
            }
        }
    }
}

int main() {
    int num[105];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    mergeSort(num, n);
}

