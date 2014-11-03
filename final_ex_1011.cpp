#include <stdio.h>
#include <ctype.h>

int charValue[27] = {
    2, 4, 6, 3, 6, 9, 4, 8, 12, 5,
    10, 15, 6, 12, 18, 7, 14, 21, 28, 8,
    16, 24, 9, 18, 27, 36, 0
};

int main() {
    char word[105];
    int sum;
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%s", word);
        sum = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            sum += charValue[tolower(word[i]) - 'a'];
        }
        printf("%d\n", sum);
    }
    return 0;
}
