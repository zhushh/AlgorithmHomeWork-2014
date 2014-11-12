#include <stdio.h>

#define MAX 205
#define INF 99999999
int map[MAX][MAX];

int main() {
    int i, j, k, n, m;
    int a, b, x;
    int start, end;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                map[i][j] = INF;
            }
        }
        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &x);
            if (map[a][b] > x)
                map[a][b] = map[b][a] = x;
        }
        for (i = 0; i < n; i++) {
            map[i][i] = 0;
        }
        scanf("%d%d", &start, &end);
    
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (map[i][j] > map[i][k] + map[k][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
    
        if (map[start][end] < INF) {
            printf("%d\n", map[start][end]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
