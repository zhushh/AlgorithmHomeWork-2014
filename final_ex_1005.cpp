#include <stdio.h>

struct que {
    int index, wait_time;
};
struct que waiter[1005];

void swap(int l, int h) {
    if (waiter[l].wait_time == waiter[h].wait_time) {
        if (waiter[l].index < waiter[h].index) {
            return;
        }
    }
    struct que temp;
    temp.wait_time = waiter[l].wait_time;
    temp.index = waiter[l].index;
    waiter[l].wait_time = waiter[h].wait_time;
    waiter[l].index = waiter[h].index;
    waiter[h].wait_time = temp.wait_time;
    waiter[h].index = temp.index;
}

void sortQueue(int low, int hig) {
    if (low < hig) {
        int l = low, h = hig, index = waiter[low].index, time = waiter[low].wait_time;
        while (l < h) {
            while (l < h && waiter[h].wait_time > time) --h;
            if (l < h) {
                swap(l, h);
                l++;
            }
            while (l < h && waiter[l].wait_time < time) ++l;
            if (l < h) {
                swap(l, h);
                h--;
            }
        }
        waiter[l].wait_time = time;
        waiter[l].index = index;
        sortQueue(low, l - 1);
        sortQueue(l + 1, hig);
    }
}

int main() {
    int i, n, time;
    double sum = 0, num = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &time);
        waiter[i].index = i + 1;
        waiter[i].wait_time = time;
    }
    sortQueue(0, n - 1);
    for (i = 0; i < n - 1; i++) {
        printf("%d ", waiter[i].index);
        num += waiter[i].wait_time;
        sum += num;
    }
    printf("%d\n", waiter[n - 1].index);
    printf("%.2lf\n", sum / n);
    return 0;
}

