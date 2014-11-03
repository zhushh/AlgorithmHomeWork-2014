#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
    int steps;
    Node(int x_ = 0, int y_ = 0, int steps_ = 1) {
        x = x_; y = y_; steps = steps_;
    }
};

int n;
int maze[32][32];
queue<Node> con;

void search(int a, int b, struct Node item) {
    if (item.x + a >= 0 && item.x + a < n
     && item.y + b >= 0 && item.y + b < n
     && maze[item.x + a][item.y + b] == 0) {
        item.x += a; item.y += b; item.steps++;
        con.push(item);
        maze[item.x][item.y] = 1;
     }
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        struct Node start;
        start.x = 0; start.y = 0; start.steps = 1;
        con.push(start);
        while (!con.empty()) {
            start = con.front();
            if (start.x == n - 1 && start.y == n - 1) {
                break;
            }
            con.pop();
            search(0, 1, start);
            search(0, -1, start);
            search(-1, 0, start);
            search(1, 0, start);
        }
        if (con.empty()) {
            cout << 0 << endl;
        } else {
            cout << start.steps << endl;
        }
        while (!con.empty()) {
            con.pop();
        }
    }
    return 0;
}

