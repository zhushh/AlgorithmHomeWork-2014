#include <iostream>
using std::cout;
using std::endl;

struct Node {
         int data;
         Node *next;
};

class LinkedList
{
public:
         LinkedList() : head(NULL), size(0) {}
         /*

                   插入一个元素content到链表的第position个位置，注意position从0开始
                   如原始链表是 1 2 3，insert(0, 5)之后变成 5 1 2 3
                   如果插入的位置在链表末尾或者之后，则直接将元素插入到链表末尾
                   如原始链表是 1 2 3，insert(50, 6)之后变成 1 2 3 6
                   第50个位置在当前链表大小之后，所以直接插入到链表末尾，也就是第3个位置
          */
         void insert(int position, int content) {
             Node *temp = new Node;
             temp->data = content;
             temp->next = NULL;
             if (size == 0) {
                 head = temp;
             } else if (position == 0) {
                 temp->next = head;
                 head = temp;
             } else if (position < size) {
                 Node *p = head;
                 for (int i = 0; i < position - 1; i++) {
                     p = p->next;
                 }
                 temp->next = p->next;
                 p->next = temp;
             } else {
                 Node *p = head;
                 for (int i = 0; i < size - 1; i++) {
                     p = p->next;
                 }
                 p->next = temp;
             }
             size++;
         }
         /*
                   删除链表的第position个元素
                   如果链表没有第position个元素，则不删除任何元素
          */
         void deleteByPosition(int position) {
             if (position < size && size > 0) {
                 if (position == 0) {
                     Node *temp = head;
                     head = head->next;
                     delete temp;
                     size--;
                     return;
                 }
                 Node *p = head;
                 for (int i = 0; i < position - 1; i++) {
                     p = p->next;
                 }
                 Node *temp = p->next;
                 p->next = temp->next;
                 delete temp;
                 size--;
             }
         }
         /*
                   将链表内容打印到屏幕，每个元素后面都跟着一个制表符，
                   并且最后一个元素的制表符后面需要换行
          */
         void print() {
             Node *p = head;
             for (int i = 0; i < size; i++) {
                 cout << p->data << '\t';
                 p = p->next;
             }
             cout << '\n';
         }
private:
         Node *head;                               // 链表头指针
         int size;                                        // 链表内元素个数
};

