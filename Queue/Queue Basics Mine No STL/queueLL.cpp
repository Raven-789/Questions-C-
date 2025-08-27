#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        // Node *front;

        Node(int val){
            data = val;
            // front = nullptr;
            next  = nullptr;
        }
};

class Queue{
    Node * qfront;
    Node * rear;
    
    public:
        Queue(){
            qfront = nullptr;
            rear = nullptr;
        }

        //Push Operation
        void enqueue(int x){
            Node *newNode = new Node(x);
            if(qfront == nullptr){

                newNode -> next =  nullptr;
                qfront = newNode;
                rear = newNode;

            }else{

                rear -> next = newNode;
                rear = newNode;
            }


        }

        //Pop operation
        void dequeue(){
            if(qfront == nullptr){
                cout<<"Stack underflow \n";
                return;
            }
            Node *temp = qfront;
            qfront = qfront -> next;//popping the element
            delete temp;
        }

        //Top element
        int front(){
            if(qfront==NULL){
                cout<<"Stack is Empty \n";
                return -1;
            }
            return qfront -> data;
        }

        //Check if empty
        bool isEmpty(){
            return qfront == NULL;
        }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout<<"Front : "<<q.front()<<endl;

    q.dequeue();
    cout<<"Front after dequeue: "<<q.front()<<endl;
    cout<< q.isEmpty()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<< q.isEmpty();
    return 0;
}