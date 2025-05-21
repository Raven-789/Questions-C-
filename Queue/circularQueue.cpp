#include<iostream>
#include<vector>
using namespace std;

class CircularQueue{
    vector <int>q;
    int front , rear , size ,capacity;

    public:
    CircularQueue(int k){
        capacity = k;
        q.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full!!"<<endl;
            return false;
        }
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear = (rear+1) % capacity;
        }

        q[rear]=val;
        size++;
        return true;
    }

    bool dequeue(){
        if (isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return false;
        }

        if (front == rear){
            front = rear = -1; //Queue becomes empty
        }else{
            front = (front +1) % capacity;
        }

        size -- ;
        return true;
    }

    int getFront(){
        if(isEmpty()) return -1;
        return q[front];
    }

    int getRear(){
        if(isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty(){
        return size ==0;
    }

    bool isFull(){
        return size == capacity;
    }

    void display(){
        if (isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        cout<<"Circular Queue: ";
        for(int i = 0 ; i < size ; ++i){
            cout<<q[front+i % capacity]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cout<<"Front : "<<cq.getFront()<<endl;
    cout<<"Rear: "<<cq.getRear()<<endl;
}
