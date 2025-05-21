#include<iostream>
#include<stack>
using namespace std;

class MinStack{
    stack <int> mainStack;
    stack <int> maxStack;

    public:
        //Push element onto stack
        void push(int x){
            mainStack.push(x);
            if(maxStack.empty() || x >= maxStack.top()){
                maxStack.push(x);
            }else{
                maxStack.push(maxStack.top());
            }
        }

        //Pop element from stack
        void pop(){
            if(!mainStack.empty()){
                mainStack.pop();
                maxStack.pop();
            }
        }

        int top(){
            return mainStack.empty() ? -1 : mainStack.top();
        }

        int getMax(){
            return mainStack.empty() ? -1 : maxStack.top();
        }

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

    cout<<"Top : "<<st.top()<<endl;     
    cout<<"Max : "<<st.getMax()<<endl;  

    st.pop();

    cout<<"Top : "<<st.top()<<endl;     
    cout<<"Max : "<<st.getMax()<<endl;  
    
}