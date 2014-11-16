#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > table(256, vector<int>(0));
vector<int> ans_code;

int bineary_search(int index, int num) {
    if (table[num].size() == 0) {
        return -1;
    }
    int low = 0, high = table[num].size() - 1;
    int mid = (high + low) / 2;
    while (low <= high) {
        if (table[num][mid] == index) {
            return index;
        } else if (table[num][mid] > index) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return -1;
}

int main() {
    int i, n, m, num;
    while (cin >> n) {
        for (i = 0; i < n; i++) {
            cin >> num;
            ans_code.push_back(num);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> num;
            table[num].push_back(i);
        }

        // 逐一从匹配到的首字符位置开始对比，
        // 所有下标在相应的表头位置的数组内可找到则满足情况
        // 反之，所有首字符相匹配的位置都没有满足的情况，则不存在子字符串
        int found = 0;
        for (i = 0; i < table[ans_code[0]].size(); i++) {
            int index = table[ans_code[0]][i];
            int k = 1;
            while (k < ans_code.size() && bineary_search(index + 1, ans_code[k]) != -1) {
                k++;
                index++;
            }
            if (k == ans_code.size()) {
                cout << table[ans_code[0]][i] << endl;
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "no solution" << endl;
        }
        for (int i = 0; i < 256; i++) {
            if (table[i].size() > 0) {
                table[i].clear();
            }
        }
        ans_code.clear();

    }
    return 0;
}
