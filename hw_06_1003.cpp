#include <stdio.h>
int a[1001];

void sort_arr(int low, int hig) {
    if (low < hig) {
        int l = low, h = hig, num = a[low];
        while (l < h) {
            while (l < h && num < a[h]) --h;
            if (l < h) a[l++] = a[h];
            while (l < h && num > a[l]) ++l;
            if (l < h) a[h--] = a[l];
        }
        a[l] = num;
        sort_arr(low, l - 1);
        sort_arr(l + 1, hig);
    }
}

int main() {
    int t, i;
    int n_persons, floor, boxNum;
    scanf("%d", &t);
    while (t-- > 0) {
        int pos, status;

        scanf("%d%d%d", &n_persons, &floor, &boxNum);
        for (i = 0; i < n_persons; i++) {
            scanf("%d%d", &pos, &status);
            if (0 == status) {
                a[i] = pos;
            } else if (1 == status) {
                a[i] = 2*floor - pos;
            }
        }
        sort_arr(0, n_persons - 1);
        int sum_time = 0;
        int last = boxNum % n_persons;
        if (last == 0) {
            sum_time += a[n_persons - 1];
            sum_time += ((boxNum / n_persons - 1)*2 + 1) * floor;
        } else {
            sum_time += a[last - 1];
            sum_time += (boxNum / n_persons * 2 + 1) * floor;
        }
        printf("%d\n", sum_time);
    }
    return 0;
}
