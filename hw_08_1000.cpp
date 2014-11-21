/*************************************************************************
	> File Name: hw_08_1000.cpp
	> Author: zhushh
	> Mail: 
	> Created Time: Fri 21 Nov 2014 04:49:41 PM CST
*************************************************************************/

#include <iostream>
using namespace std;

int arr[1000];

void print(int num) {
    for (int i = 0; i < num - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr[num - 1] << endl;
}

void selected_sort(int num) {
    int i, j;
    int index, temp;
    for (i = 0; i < num - 1; i++) {
        index = i;
        temp = arr[i];
        for (j = i + 1; j < num; j++) {
            if (arr[j] < temp) {
                index = j;
                temp = arr[j];
            }
        }
        arr[index] = arr[i];
        arr[i] = temp;
        print(num);
    }
}

int main(void) {
    int t;
    cin >> t;
    while (t-- > 0) {
        int num, a;
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> arr[i];
        }
        selected_sort(num);
    }
    return 0;
}

