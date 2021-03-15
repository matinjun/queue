#include <iostream>

class Queue {
    int * a;
    int len;
    int head;
    int tail;
public:
    Queue(int n = 10):len(n) {
        a = new int[len];
        head = tail = 0;
    }
    ~Queue() {
        delete[] a;
    }
    int top() const {return a[head];}
    void enqueue(int item) {
        a[tail] = item;
        tail = (tail + 1) % len;
    }
    void dequeue() {
        head = (head + 1) % len;
    }
    bool empty() const {return head == tail;}
    bool overflow() const {return (tail + 1) % len == head;}
    // 扩展空间
    void extend() {
        int * b = new int[len * 2];
        for(int i = head, j = 0; i != tail; i = (i + 1) % len,j++) {
            b[j] = a[i];
        }
        delete []a;
        a = b;
        len = len * 2;
    }
};

int main(int, char**) {
    Queue queue;
    for(int i = 0; i < 20; ++i) {
        if(queue.overflow()) {
            queue.extend();
        }
        queue.enqueue(i);
    }
    while(!queue.empty()) {
        std::cout << queue.top() << " ";
        queue.dequeue();
    }
    std::cout << std::endl;
    return 0;
}
