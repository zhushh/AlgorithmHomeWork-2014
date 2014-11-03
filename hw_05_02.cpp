#include <iostream>
#include <vector>
#include <string>
using namespace std;

int used[20];
vector<int> cur;

void print() {
   cout << '{';
   for (int i = 0; i < cur.size(); i++) {
      cout << cur[i];
      if (i < cur.size() - 1)
         cout << ',';
   }
    cout << '}' << endl;
}
void create_sub(int size) {
   print();
   for (int i = 0; i < size; i++) {
      if (!used[i]) {
         cur.push_back(i + 1);
         used[i] = 1;
         create_sub(i + 1);
         cur.pop_back();
         used[i] = 0;
      }
   }
}

int main() {
   int t, m;
   cin >> t;
   while (t-- > 0) {
      cin >> m;
      for (int i = 0; i < m; i++) {
         used[i] = 0;
      }
      create_sub(m);
   }
   return 0;
}
