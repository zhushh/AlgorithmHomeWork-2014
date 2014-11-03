#include <iostream>
#include <queue>
using namespace std;

queue<int> number;

int main() {
    int t, num;
    cin >> t;
    while (t-- > 0) {
          cin >> num;
          for (int i = 1; i <= num; i++) {
              number.push(i);
          }
          while (number.size() > 2) {
                num = number.front();
                number.pop();
                cout << num << " ";
                num = number.front();
                number.pop();
                number.push(num);
          }
          while (!number.empty()) {
                cout << number.front() << " ";
                number.pop();
          }
          cout << endl;
    }
    return 0;
}

