#include <cstdio>
#include <cstdlib>

void print(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}
int insert_heap(int *arr, int &current, int low, int high) {
    int large;
    large = 2 * low + 1;
    while (large <= high) {
        if (large < high && arr[large] < arr[large + 1]) {
            large++;
        }
        if (current >= arr[large]) {
            break;
        } else {
            arr[low] = arr[large];
            low = large;
            large = 2 * low + 1;
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
void sort_array(int *arr, int n) {
    int current;
    int last;
    build_heap(arr, n);
    print(arr, n);
    for (last = n - 1; last > 0; last--) {
        current = arr[last];
        arr[last] = arr[0];
        insert_heap(arr, current, 0, last - 1);
        print(arr, n);
    }
}
int main(void) {
    int *arr;
    int n;
    while (scanf("%d", &n) != EOF) {
        while ((arr = (int *)malloc((n + 1) * sizeof(int))) == NULL);
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        sort_array(arr, n);
        free(arr);
    }
    return 0;
}
