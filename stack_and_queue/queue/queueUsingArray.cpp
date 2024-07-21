#include <bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue() {
        maxSize = 16; // Default max size
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement) {
        if (currSize == maxSize) {
            cout << "Queue is full" << endl;
            exit(1);
        }
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = newElement;
        currSize++;
    }

    void pop() {
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
    }

    int top() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size() {
        return currSize;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element: " << q.top() << endl;
    cout << "The size of the queue before deletion: " << q.size() << endl;
    q.pop();
    cout << "The peek of the queue after deleting an element: " << q.top() << endl;
    cout << "The size of the queue after deleting an element: " << q.size() << endl;
    return 0;
}

