
#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
public:
    int fr, bk, size, capacity;
    vector<int> st;

    MyCircularQueue(int k) {
        fr = 0;
        bk = 0;
        size = 0;
        capacity = k;
        st.resize(k);
    }

    bool enQueue(int value) {
        if(size == capacity)
            return false;

        st[bk] = value;

        bk++;
        if(bk == capacity)
            bk = 0;

        size++;

        return true;
    }

    bool deQueue() {
        if(size == 0)
            return false;

        fr++;

        if(fr == capacity)
            fr = 0;

        size--;

        return true;
    }

    int Front() {
        if(size == 0)
            return -1;

        return st[fr];
    }

    int Rear() {
        if(size == 0)
            return -1;

        if(bk == 0)
            return st[capacity - 1];

        return st[bk - 1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */