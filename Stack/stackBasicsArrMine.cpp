#include<iostream>
#include<stack>
using namespace std;

class Stack {

    public:
        int * arr;
        int top;
        int size;
        

        Stack (int size){
            this -> size = size;
            arr = new int [size];
            top = -1;
        }

        void push(int element){
            if(size - top > 1){
                top++;
                arr[top] = element;
            }else{
                cout<<"Stack Overflow!"<<endl;
            }
        }

        void pop(){
            if(top >= 0){
                top--;
            }else{
                cout<< "Stack Underflow!"<<endl;
            }

        }

        int peek(){
            if(top >= 0){
                return arr[top];
            }else{
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
        }

        bool isEmpty(){
            if(top < 0){
                cout<<"Stack is Empty"<<endl;
                return 1;
            }else{
                cout<<"Stack is not Empty"<<endl;
                return 0;
            }
        }

};


int main(){


    Stack st(5);//we don't need to allocate space for it as we're allocating array to it in the constructor see it 

    st.push(43);
    st.push(42);
    st.push(44);


    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;


    st.isEmpty();

    st.push(66);

    cout<<st.peek()<<endl;
    st.isEmpty();
    st.pop();
    st.pop();

    st.push(43);
    st.push(42);
    st.push(44);
    st.push(43);
    st.push(42);
    st.push(44);//stack hit overflow here

















    // //creation of stack
    // stack<int> s;

    // //push operation
    // s.push(2);
    // s.push(3);

    // //pop
    // s.pop();

    // cout << "Printing top element " << s.top() << endl;

    // if(s.empty()){
    //     cout << "Stack is empty " << endl;
    // }
    // else{
    //     cout << "stack is not empty " << endl;
    // }

    // cout << "size of stack is " << s.size() << endl;


}