#include <iostream>
using namespace std;

int a[105][105];
int visited[105];   // 用于标记是否某个下标是否已经属于某一连通块

int main() {
    int n, m;
    int u, v;
    for (int i = 0; i < 105; i++) {
        visited[i] = 0;
        for (int j = 0; j < 105; j++) {
            a[i][j] = 0;
        }
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;  // 标记 u 和 v 相通，1为相通，0为未通
    }
    int count = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = i; j < n + 1; j++) {
            // 遍历访问每个坐标(u, v)
            // 判断这个坐标是否已经属于一个连通块
            // 当visited[i] 和 visited[j]都为0时，表示坐标(i, j)不属于任何一个连通块
            // 如果此时(i, j)的值为1，那么就是一个新的连通块出现
            if (visited[i] == 0 && visited[j] == 0 && a[i][j] == 1) {
                count++;
                visited[i] = visited[j] = 1;
            }
            // 如果(i, j)属于某一连通块，且这个坐标值为1，标记下标为已经属于某一连通块
            else if (a[i][j] == 1) {
                visited[i] = visited[j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        if (visited[i] == 0) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

