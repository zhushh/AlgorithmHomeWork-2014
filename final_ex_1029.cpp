#include <cstdio>

#define MAX 105
char str[MAX];
int curp = 0;


char get_char() {
    char c;
    void put_char();
    if (curp < MAX && (c = getchar()) != '_' && c != '\n') {
        str[curp++] = c;
    } else if (curp < MAX) {
        put_char();
        putchar(c);
    }
    return c;
}
void put_char() {
    while (curp > 0) {
        putchar(str[--curp]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while (t-- > 0) {
        while (get_char() != '\n')
            ;
    }
    return 0;
}

