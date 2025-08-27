#include<iostream>
#include<cstring>//for memset
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


class DoublyEndedQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    DoublyEndedQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void pushfront(int data){

        // if((rear +1) % size == front){//overflow condition THIS ONE IS FOR PUSHREAR
        if ((front - 1 + size) % size == rear) { // Correct overflow condition for pushfront (check if this new front position would collide with rear, which means the queue is full)

            cout<<"Doubly Ended Queue is Full"<<endl;

        }
        else{
            if(front == -1){//first element

                front = rear = 0;

            }else if(front == 0){//cyclic nature

                front = size -1;// its on 0 and for pushing its front-- so to go back from 0 to n we use size -1 ok

            }else{
                front--;
            }

            arr[front] = data;
        }

    }

    int poprear(){

        if(front == -1){// Underflow condition ofr popfront is also same

            cout<<"Doubly Ended Queue Underflow"<<endl;
            return -1;

        }
        int ele = arr[rear];
        if(front == rear){// only 1 element left to pop so reset the whole queue

            front = rear = -1;

        }else if(rear == 0){// circular wrap around

            rear = size -1;

        }else{

            rear--;

        }
        return ele;

    }

    void pushrear(int data){

        if((rear +1) % size == front){

            cout<<"Doubdly Ended Queue Overflow"<<endl;
            return;

        }else if(rear == -1 && front == -1){//1st element

            rear = front = 0;

        }else if(rear == size -1 && front != 0){//Circular wrap around(you forgot the -1 here ok)

            rear = 0;

        }else{//Normal push from rear

            rear++;

        }
        arr[rear] = data;

    }

    int popfront(){

        if(front == -1){// Underflow condition ofr poprear is also same

            cout<<"Doubly Ended Queue Underflow"<<endl;
            return -1;

        }
        int ele = arr[front];
        if(front == rear){//only 1 element left

            front = rear = -1;

        }else if(front == size -1 && rear != 0){

            front = 0;

        }else{
            front++;
        }

        return ele;

    }

    int getFront(){

        if(front == -1){
            cout<<"Doubly Ended Queue Underflow"<<endl;
            return -1;
        }else{
            return arr[front];
        }

    }

    int getRear(){

        if(front == -1){
            cout<<"Doubly Ended Queue Underflow"<<endl;
            return -1;
        }else{
            return arr[rear];
        }

    }

    ~DoublyEndedQueue() {
    delete[] arr;
    }

};


int main() {
    // Create a deque of size 5
    DoublyEndedQueue dq(5);

    // Initial pops on empty queue
    dq.popfront(); // Underflow
    dq.poprear();  // Underflow
    dq.getFront(); // Underflow
    dq.getRear();  // Underflow

    cout << "Pushing 10 to rear" << endl;
    dq.pushrear(10); // First element

    cout << "Pushing 20 to rear" << endl;
    dq.pushrear(20);

    cout << "Pushing 30 to front" << endl;
    dq.pushfront(30);

    cout << "Pushing 40 to front" << endl;
    dq.pushfront(40);

    cout << "Pushing 50 to rear (should fill the queue)" << endl;
    dq.pushrear(50); // Should succeed and fill the queue

    cout << "Attempting overflow (should fail)" << endl;
    dq.pushrear(60); // Overflow

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    cout << "Popping front: " << dq.popfront() << endl;
    cout << "Popping rear: " << dq.poprear() << endl;

    cout << "Pushing 70 to front after pop" << endl;
    dq.pushfront(70);

    cout << "Pushing 80 to rear after pop" << endl;
    dq.pushrear(80);

    cout << "Final front element: " << dq.getFront() << endl;
    cout << "Final rear element: " << dq.getRear() << endl;

    cout << "Emptying the queue:" << endl;
    while (dq.getFront() != -1) {
        cout << "Pop front: " << dq.popfront() << endl;
    }

    cout << "Attempting underflow after emptying:" << endl;
    dq.popfront(); // Underflow
    dq.poprear();  // Underflow

    return 0;
}
