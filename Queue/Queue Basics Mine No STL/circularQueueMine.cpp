#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

//My Approach (didn't work)-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Cqueue{
    public:
        int * arr;
        int rear;
        int qfront;
        int size;//size was not taken from user in question
        // int capacity;

        Cqueue(int n){
            
            size = n;//it counts how many spaces are filled in queue
            // capacity = n;//this shows the total no. of spaces in queue
            qfront = 0;
            rear = qfront = -1;
            arr = new int[n];
            
        }


        void enqueue(int data){

            // cout<< (qfront -1) % (size -1) << "   "<<rear<<endl;
            // if(( qfront == 0 && rear == size - 1 ) || (rear ==   (qfront -1) % size ) ){
            if ((qfront == 0 && rear == size - 1) || (rear + 1) % size == qfront){
            // if((rear + 1) % size == qfront){
                
                cout<<"Circular Queue Overflow"<<endl;
            }
            else{
                if(qfront == -1){

                    qfront = rear = 0;
                    arr[rear] = data;
                    
                }
                else if(rear == size -1 && qfront != 0){
                    rear = 0;
                    arr[rear] = data;
                }
                else{

                    rear = (rear +1 ) % size;
                    arr[rear] = data;

                }
            }
                
        }
    
    
        int dequeue(){

            if(rear == -1 ){
                cout<<"Circular Queue Underflow"<<endl;
            }
            else{
                
                int ele = arr[qfront];
                if(qfront == size - 1){

                    qfront = rear = -1;//resettign the queue as we've popped all the elements

                }else{

                    qfront = (qfront + 1) % size;

                }

                // if(qfront == rear){
                //     qfront = rear = -1;
                // }
                return ele;

            }

        }

        int front(){

            if(size == 0){
                return -1;
            }else{
                return arr[qfront];
            }

        }
};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//His approach
// Time Complexity O(1)
// Space Complexity O(n)

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whther queue is full
        // if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
        if ( (rear + 1) % size == front){
            cout << "Queue is Full"<<endl;
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {// when front is in mid from popping and rear has to add elements in the dequeued elements' place so it has to wrap around and goto 0
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    int frontt(){

        if(front == -1){
            return -1;
        }else{
            return arr[front];
        }

    }

};

int main(){

    CircularQueue c(5);

    c.enqueue(30);
    c.enqueue(20);
    c.enqueue(60);
    c.enqueue(20);
    c.enqueue(70);
    // cout<<"Popped: "<<c.dequeue()<<endl;
    // cout<<"Popped: "<<c.dequeue()<<endl;
    // cout<<"Popped: "<<c.dequeue()<<endl;
    // cout<<"Popped: "<<c.dequeue()<<endl;
    cout<<"Popped: "<<c.dequeue()<<endl;
    cout<<"Popped: "<<c.dequeue()<<endl;
    c.enqueue(10);
    c.enqueue(40);
    c.enqueue(50);
    cout<<"Popped: "<<c.dequeue()<<endl;
    cout<<"Popped: "<<c.dequeue()<<endl;
    // c.dequeue();
    // c.dequeue();
    cout<<c.frontt()<<endl;

}