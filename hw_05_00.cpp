/***********************************************************************
 *  > File Name: 061000_.cpp
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 02 Nov 2014 11:47:56 AM CST
***********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;
};

char map[12][12];
vector<struct point> path;
int m, n;
int to[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

bool isEmpty(int x, int y) {
    if (x >= 0 && x < m && y >= 0 && y < n && map[x][y] == '0') {
        return true;
    } else {
        return false;
    }
}
void print() {
    for (int i = 0; i < path.size(); i++) {
        cout << '(' << path[i].x << ',' << path[i].y << ')';
        if (i < path.size() - 1) cout << ' ';
    }
    cout << endl;
}
bool search(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        print();
        return true;
    } else {
        struct point temp;
        for (int i = 0; i < 4; i++) {
            if (isEmpty(x + to[i][0], y + to[i][1])) {
                temp.x = x + to[i][0];
                temp.y = y + to[i][1];
                map[temp.x][temp.y] = '1';
                path.push_back(temp);
                if (search(temp.x, temp.y)) {
                    return true;
                }
                path.pop_back();
                map[temp.x][temp.y] = '0';
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> map[i];
        }
        if (map[0][0] == '1' || map[m - 1][n - 1] == '1') {
            cout << "no" << endl;
            continue;
        }
        struct point temp;
        temp.x = 0;
        temp.y = 0;
        map[temp.x][temp.y] = '1';
        path.push_back(temp);
        if (!search(0, 0)) {
            cout << "no" << endl;
        }
        path.clear();
    }
    return 0;
}

