#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{
    Node * topNode;

    public:
        Stack(){
            topNode = NULL;
        }

        //Push Operation
        void push(int x){
            Node *newNode = new Node(x);
            newNode -> next = topNode;
            topNode = newNode;
        }

        //Pop operation
        void pop(){
            if(topNode == NULL){
                cout<<"Stack underflow \n";
                return;
            }
            Node *temp = topNode;
            topNode = topNode -> next;
            delete temp;
        }

        //Top element
        int top(){
            if(topNode==NULL){
                cout<<"Stack is Empty \n";
                return -1;
            }
            return topNode -> data;
        }

        //Check if empty
        bool isEmpty(){
            return topNode == NULL;
        }
};

int main(){
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);

    cout<<"Top element: "<<st.top()<<endl;

    st.pop();
    cout<<"Top after pop: "<<st.top()<<endl;
    
}