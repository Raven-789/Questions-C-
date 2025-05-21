#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    stack <int> mainStack;
    stack <int> minStack;

    public:
        //Push element onto stack
        void push(int x){
            mainStack.push(x);

            if(minStack.empty() || x <= minStack.top()){
                minStack.push(x);
            }else{
                minStack.push(minStack.top());
            }
        }

        //Pop element from stack
        void pop(){
            if(!mainStack.empty()){
                mainStack.pop();
                minStack.pop();
            }
        }

        //Get top element
        int top(){
            if(!mainStack.empty()) return mainStack.top();
            return -1;
        }

        //Get minimum element in O(1)
        int getMin(){
            if(!minStack.empty()) return minStack.top();
            return -1;
        }

        //Check if emtpy
        bool isEmpty(){
            return mainStack.empty();
        }
};

int main(){
    MinStack st;
    
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout<<"Top : "<<st.top()<<endl;     // 2
    cout<<"Min : "<<st.getMin()<<endl;  //2

    st.pop();

    cout<<"Top : "<<st.top()<<endl;         //7
    cout<<"Min : "<<st.getMin()<<endl;      //3
    
}