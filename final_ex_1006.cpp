#include <iostream>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;

struct Node {
    int x;
    int y;
    int steps;
};

int maze[35][35];
queue<Node> contain;

void search(int x, int y, Node cur, int n) {
    if (cur.x + x >= 1 && cur.x + x < n + 1 // x is not overflow
     && cur.y + y >= 1 && cur.y + y < n + 1 // y is not overflow
     && maze[cur.x + x][cur.y + y] == 0) {  // this step can walk
        cur.x += x; cur.y += y; cur.steps++;
        contain.push(cur);
        maze[cur.x][cur.y] = 1;
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                cin >> maze[i][j];
            }
        }
        Node start;
        start.x = 1; start.y = 1; start.steps = 1;
        contain.push(start);
        while (!contain.empty()) {  // start search one by one
            start = contain.front();
            if (start.x == n && start.y == n) {
                cout << start.steps << endl;
                break;
            }
            contain.pop();
            search(0, 1, start, n);
            search(0, -1, start, n);
            search(1, 0, start, n);
            search(-1, 0, start, n);
        }
        if (contain.empty()) {  // determine if the path was found
            cout << 0 << endl;
        }
        while (!contain.empty()) {  // clear contain
            contain.pop();
        }
    }
    return 0;
}

