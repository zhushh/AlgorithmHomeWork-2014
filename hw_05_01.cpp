#include <stdio.h>
#include <memory.h>

const int N = 8;

int map[N + 1][N + 1];
int num[N * N + 2];
int to[N][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2}, {1, 2}, {2, -1}, {2, 1}
};

bool canMove(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && map[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}
int count_steps(int x, int y) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (canMove(x + to[i][0], y + to[i][1])) {
            count++;
        }
    }
    return count;
}
void sort_steps(int a[], int b[], int size) {
    if (size <= 0) return;
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                temp = b[j];
                b[j] = b[j - 1];
                b[j - 1] = temp;
            }
        }
    }
}
void print() {
    for (int i = 0; i < N * N; i++) {
        printf("%d", num[i]);
        if (i < N * N - 1)
            printf(" ");
    }
    printf("\n");
}
bool search(int cur_x, int cur_y, int steps) {
    if (steps == N * N) {
        print();
        return true;
    }
    int k = 0;
    int count[N], possible[N];
    for (int i = 0; i < N; i++) {
        if (canMove(cur_x + to[i][0], cur_y + to[i][1])) {
            count[k] = count_steps(cur_x + to[i][0], cur_y + to[i][1]);
            possible[k++] = i;
        }
    }
    sort_steps(count, possible, k);

    for (int i = 0; i < k; i++) {
        cur_x += to[possible[i]][0];
        cur_y += to[possible[i]][1];
        map[cur_x][cur_y] = steps + 1;
        num[steps] = cur_x * N + cur_y + 1;
        if (search(cur_x, cur_y, steps + 1)) {
            return true;
        }
        map[cur_x][cur_y] = 0;
        cur_x -= to[possible[i]][0];
        cur_y -= to[possible[i]][1];
    }
    return false;
}

int main() {
    int n, x, y;
    while (scanf("%d", &n) == 1) {
        if (n == -1) break;
        memset(map, 0, sizeof(map));
        x = (n - 1)/N;
        y = n - N * x;
        map[x][y] = 1;
        num[0] = n;
        search(x, y, 1);
    }
    return 0;
}
