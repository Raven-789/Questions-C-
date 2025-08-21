#include<iostream>
#include<stack>
using namespace std;

template <typename T>
void printStack(stack<T> s) {
    bool chk =s.empty();
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "ok" << endl;
}

void pushStackInt(stack <int> &s, int num){

    int r, q;
    stack <int> n;
    while(num){

        r = num % 10;
        n.push(r);
        num = num /10;

    }
    while(!n.empty()){
        s.push(n.top());
        n.pop();
    }
    // printStack(s);
    cout<<"Push ok"<<endl;
}

//My Approach---------------------------------------------------------------------------------------------------------------------------
//Time Complexity O()
//Space Complexity O()

template <typename T>
void insertAtBottom(stack <T> &s, int num){

    if(s.empty()){
        cout<<"Inserted at bottom: "<<num<<endl;
        s.push(num);
        return ;
    }

    int element = s.top();
    s.pop();

    insertAtBottom(s,num);

    s.push(element);

}

//My approach--------------------------------------------------------------------------------------------------------------------------------------------------

//HIS IS BETTER THAN MINE BUT YOUU ATLEAST TRIED YARR
//Time Complexity O(n²)
//Space Complexity O(n) check it ok


void insertSorted(stack <int> &s, int sz, int ele, int digit = -1111111111){
    
    if(s.empty()){//if the stack is empty
        s.push(ele);
        cout<<s.top()<<endl;
        return;
    }
    // cout<<s.top()<<endl; //too see the top for debugging purposes
    if(ele <= s.top()){//if element we're inserting is greater than the existing stack element then we've to pop the existing stack element
        digit = s.top();
        s.pop();
    }
    //else if is for avoiding segmentation fault when s.top is empty
    ////this condition has to be below as digit will be updated in that and only after
    else if(ele > s.top()){//if the element is smaller than the existing stack element then we've to insert our new element
        if(digit == -1111111111){// if the new element we're inserting is at the top of the stack 
            s.push(ele);
            
            return ;
        }else{// if the new element we're inserting is not at the top of the stack then we've to make sure that we put that recursive call's popped element back in as it won't be in backtracking
            s.push(ele);
            s.push(digit);//as this iteration call will be returned and we'll go to 7's call (see the first example ok)
            return ;
        }

    }
    
    insertSorted(s,sz,ele);
    s.push(digit);
    

}

void solve(stack <int> &s, int sz, int min, int cnt = 0){

    if(s.empty()){
        return;
    }

    int ele = s.top();
    s.pop();

    solve(s,sz,min,cnt);

    insertSorted(s,sz,ele);

}

void stackSort(stack <int> &s){
    int min;
    solve(s,s.size(),min);
}


//His approach--------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n²) (his is better)
//Space Complexity O(1) check it ok

void sortedInsert(stack <int> &s, int num){
    
    if(s.empty() || !s.empty() && s.top() < num){
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    //recursive call
    sortedInsert(s,num);
    s.push(n);

}

void stackSortHis(stack <int> &s){

    //base case
    if(s.empty()){
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    stackSortHis(s);
    sortedInsert(s,num);

}



int main(){

    stack <int> s;
    //first example don't delete it------------------------------------------------------------------
    int num = 1574398;//first example don't delete it you've used it in comments OKAY
//--------------------------------------------------------------------------------------------------

    // int num = 72731;
    // pushStackInt(s,num);
    // printStack(s);
    // stackSort(s);
    // printStack(s);

    //His (approach which was better)
    // int num = 12456;
    pushStackInt(s,num);
    printStack(s);
    stackSortHis(s);
    printStack(s);
}