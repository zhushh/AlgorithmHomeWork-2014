#include <stdio.h>

char str1[1000];
char str2[1000];
int table[1000][1000];

int main() {
    int i, j, maxLen;
    while (scanf("%s %s", str1, str2) != EOF) {
        maxLen = 0;
        for (i = 0; str1[i] != '\0'; i++) table[0][i] = 0;
        for (j = 0; str2[j] != '\0'; j++) table[j][0] = 0;
        for (i = 1; str1[i - 1] != '\0'; i++) {
            for (j = 1; str2[j - 1] != '\0'; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                } else if (table[i - 1][j] > table[i][j - 1]) {
                    table[i][j] = table[i - 1][j];
                } else {
                    table[i][j] = table[i][j - 1];
                }
            }
            if (maxLen < table[i][j]) {
                maxLen = table[i][j];
            }
        }
        printf("%d\n", maxLen);
    }
    return 0;
}
