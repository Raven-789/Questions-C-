#include <iostream>
#include <stack>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) return -1; // Queue is empty
            transfer();  // Transfer elements from stack1 to stack2
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) return -1; // Queue is empty
            transfer();
        }
        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingTwoStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeue: " << q.dequeue() << endl; // 1
    cout << "Dequeue: " << q.dequeue() << endl; // 2
    q.enqueue(4);
    cout << "Front element: " << q.front() << endl; // 3
    cout << "Dequeue: " << q.dequeue() << endl; // 3
    cout << "Dequeue: " << q.dequeue() << endl; // 4
    cout << "Dequeue: " << q.dequeue() << endl; // -1 (Queue is empty)

    return 0;
}
