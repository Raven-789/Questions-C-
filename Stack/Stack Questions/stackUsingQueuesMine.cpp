#include <iostream>
#include <queue>

using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

    // Helper function to transfer elements from q1 to q2
    void transfer() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }

public:
    void push(int x) {
        q1.push(x);
    }

    int pop() {
        if (q1.empty()) return -1;  // Stack is empty

        transfer();  // Transfer all but the last element to q2
        int top = q1.front(); 
        q1.pop();
        swap(q1, q2);  // Swap q1 and q2 for the next operation
        return top;
    }

    int top() {
        if (q1.empty()) return -1;  // Stack is empty

        transfer();  // Transfer all but the last element to q2
        int top = q1.front();
        q2.push(top);  // Move it back to q2
        swap(q1, q2);  // Swap q1 and q2
        return top;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top: " << stack.top() << endl;  // 30
    cout << "Pop: " << stack.pop() << endl;  // 30
    cout << "Pop: " << stack.pop() << endl;  // 20
    cout << "Top: " << stack.top() << endl;  // 10
    cout << "Pop: " << stack.pop() << endl;  // 10

    if (stack.isEmpty()) cout << "Stack is empty!" << endl;  // Stack is empty!

    return 0;
}
