#include <iostream>
using std::cout;
using std::endl;
class MyArray {
    public:
        MyArray() : size(0) {
            for (int i = 0; i < 100; i++) {
                contents[i] = 0;
            }
        }
         /*
                   插入一个元素content到数组的第position个位置，注意position从0开始
                   如原始数组是 1 2 3，insert(0, 5)之后变成 5 1 2 3
                   如果插入的位置在数组末尾或者之后，则直接将元素插入到数组末尾
                   如原始数组是 1 2 3，insert(50, 6)之后变成 1 2 3 6
                   第50个位置在当前数组大小之后，所以直接插入到数组末尾，也就是第3个位置
          */
         void insert(int position, int content) {
             if (size <= position) {
                 contents[size++] = content;
             } else {
                 int *temp = new int[size - position + 1];
                 for (int i = position; i < size; i++) {
                     temp[i - position] = contents[i];
                 }
                 size++;    // increase size
                 contents[position] = content;
                 for (int i = position + 1; i < size; i++) {
                     contents[i] = temp[i - position - 1];
                 }
             }
         }
         /*
                   删除数组的第position个元素
                   如果数组没有第position个元素，则不删除任何元素
          */
         void deleteByPosition(int position) {
             if (position >= size) {
                 return;
             } else {
                 size--;    // decrease size
                 for (int i = position; i < size; i++) {
                     contents[i] = contents[i+1];
                 }
             }
         }
         /*
                   将数组内容打印到屏幕，每个元素后面都跟着一个制表符，
                   并且最后一个元素的制表符后面需要换行
          */
         void print() {
             for (int i = 0; i < size; i++) {
                 cout << contents[i] << '\t';
             }
             cout << endl;
         }
    private:
         int contents[100];                   // 数组，用来存放元素
         int size;                                        // 数组内元素个数
};

