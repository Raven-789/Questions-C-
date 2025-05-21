#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector <int>v;
    int capacity;
    public:
        //Constructor with optional capacity
        Stack(int cap = 1000){
            capacity =  cap;
        }

        // Push operation
        void push(int x){
            if(isFull()){
                cout<<"Stack Overflow\n";
                return;
            }
            v.push_back(x);
        }

        //Pop operation
        void pop(){
            if(is_Empty()){
                cout<<"Stack Underflow\n";
                return;
            }
            v.pop_back();
        }

        //Top element
        int top(){
            if(is_Empty()){
                cout<<"Stack is Empty\n";
                return -1;
            }
            return v.back();
        }

        //Check if stack is empty
        bool is_Empty(){
            return v.empty();
        }

        //Check if stack is full
        bool isFull(){
            return v.size() == capacity;
        }

        //Size of stack
        int size(){
            return v.size();
        }
};

int main(){
    Stack st(3);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<"Top element: "<<st.top()<<endl;

    st.pop();
    cout<<"Top after pop: "<<st.top()<<endl;

    cout<<"Stack size: "<<endl;

    if(st.isFull())
        cout<<"Stack is Full \n";
    else
        cout<<"Stack is not Ful \n";

    if(st.is_Empty())
        cout<<"Stack is Emtpy\n";
    else
        cout<<"Stack is not Empty\n";
}