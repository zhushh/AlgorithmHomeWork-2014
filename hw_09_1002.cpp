#include <cstdio>
#include <cstdlib>

int insert_heap(int *arr, int &current, int low, int high) {
    int small;
    small = 2 * low + 1;
    while (small <= high) {
        if (small < high && arr[small] > arr[small + 1]) {
            small++;
        }
        if (current <= arr[small]) {
            break;
        } else {
            arr[low] = arr[small];
            low = small;
            small = 2 * low + 1;
        }
    }
    arr[low] = current;
}
void build_heap(int *arr, int n) {
    int low;
    for (low = n / 2 - 1; low >= 0; low--) {
        int current = arr[low];
        insert_heap(arr, current, low, n - 1);
    }
}
void sort_array(int *arr, int k) {
    int current;
    int last;
    // build_heap(arr, k);
    for (last = k - 1; last > 0; last--) {
        current = arr[last];
        arr[last] = arr[0];
        insert_heap(arr, current, 0, last - 1);
    }
}
int main(void) {
    int *arr;
    int n, k, num;
    while (scanf("%d%d", &n, &k) != EOF) {
        while ((arr = (int *)malloc((k + 1) * sizeof(int))) == NULL);
        for (int i = 0; i < k; i++) {
            scanf("%d", arr+i);
        }
        build_heap(arr, k);     // construct smallest heap
        for (int i = k; i < n; i++) {
            scanf("%d", &num);
            if (num > arr[0]) {
                insert_heap(arr, num, 0, k - 1);
            }
        }
        sort_array(arr, k);
        for (int i = 0; i < k - 1; i++) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[k - 1]);
        free(arr);
    }
    return 0;
}
