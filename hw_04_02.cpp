#include <iostream>
using namespace std;

void solveProblem(int f, int t, int s, int n) {
    if (n == 0) {
        return;
    }
    solveProblem(f, s, t, n - 1);
    cout << "move disk " << n << " from peg " << f << " to peg " << t << endl;
    solveProblem(s, t, f, n - 1);
}
int main() {
    int t, n;
    int f = 1, s = 2, te = 3;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        solveProblem(f, te, s, n);
    }
    return 0;
}
