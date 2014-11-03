#include <iostream>
using namespace std;
enum ErrorCode {
    success,
    underflow,
    overflow
};

const int maxQueue = 100;
template <class QueueEntry>
class MyQueue {
    public:
        MyQueue() {
            front = rear = 0;
        }
        bool empty() const {
            if (front == rear) {
                return true;
            } else {
                return false;
            }
        }
        ErrorCode append(const QueueEntry &item) {
            if ((rear + 1)%maxQueue == front) { 
                return overflow;
            } else { 
                entry[rear++] = item;
                if (rear == maxQueue) {
                    rear = 0;
                }
                return success;
            }
        }
        ErrorCode serve() {
            if (!empty()) {
                front++;
                if (front == maxQueue) {
                    front = 0;
                }
                return success;
            } else {
                return underflow;
            }
        }
        ErrorCode retrieve(QueueEntry &item) const {
            if (empty()) {
                return underflow;
            } else {
                item = entry[front];
                return success;
            }
        }
        bool full() const {
            if ((rear + 1)%maxQueue == front) {
                return true;
            } else {
                return false;
            }
        }
        int size() const {
            if (empty()) {
                return 0;
            } else {
                int count = 0, i = front;
                while (i != rear) {
                    count++;
                    i++;
                    if (i == maxQueue) {
                        i = 0;
                    }
                }
                return count;
            }
        }
        void clear() {
              front = rear = 0;
        }
        ErrorCode retrieve_and_serve(QueueEntry &item) {
            if (empty()) {
                return underflow;
            } else {
                item = entry[front];
                front++;
                if (front == maxQueue) {
                    front = 0;
                }
                return success;
            }
        }
    private:
        int front;                             // ????
        int rear;                              // ????
        QueueEntry entry[100];       // ????
};

int main() {
    MyQueue<int> que;
    int n, num;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        que.append(i);
    }
    while (!que.empty()) {
        que.retrieve_and_serve(num);
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

