class MyCircularDeque {
public:
    vector<int> q;
    int front = 0;
    int size = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        q.assign(k, 0);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : q[front];
    }

    int getRear() {
        return isEmpty() ? -1 : q[(front + size - 1) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
