#include <stdio.h>

int main() {
    int i, t, n;
   scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d", &n);
        int num, nearest = 0, longest = 0;
        scanf("%d", &nearest);
        longest = nearest;
        for (i = 1; i < n; i++) {
            scanf("%d", &num);
            if (num > longest) {
                longest = num;
            } else if (num < nearest) {
                nearest = num;
            }
        }
        printf("%d\n", 2*(longest - nearest));
    }
    return 0;
}
