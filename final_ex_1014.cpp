#include <iostream>
using std::cin;
using std::endl;
using std::cout;

#define MAX 201
#define INF 100000006

int m, n;
int dist[MAX];
int visited[MAX];
int graph[MAX][MAX];

int dijkstra(int start, int end) {
    for (int i = 0; i < n; i++) {   // init param
        visited[i] = false;
        dist[i] = graph[start][i];
    }
    visited[start] = true;
    dist[start] = 0;
    for (int i = 0; i < n; i++) {   // find path
        int index = -1;
        int min = INF;
        for (int w = 0; w < n; w++) {
            if (!visited[w] && min > dist[w]) {
                index = w;
                min = dist[w];
            }
        }
        if (index < 0) break;   // can't find path
        else visited[index] = true;
        for (int k = 0; k < n; k++) {
            if (!visited[k]) {
                if (dist[index] + graph[index][k] < dist[k]) {
                    dist[k] = dist[index] + graph[index][k];
                }
            }
        }
    }
    return dist[end];
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = INF;
            }
            graph[i][i] = 0;
        }
        int a, b, x;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> x;
            if (graph[a][b] > x) {
                graph[a][b] = graph[b][a] = x;
            }
        }
        cin >> a >> b;
        if (dijkstra(a, b) < INF) {
            cout << dist[b] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
