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


void pushStackStr(stack <char> &s, string str){ // we made it void as we've used reference variable

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        s.push(ch);

    }
}

//His Approach my take-----------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n²)
//Space Complexity O(1)
// You are not allowed to use any extra space other than the internal stack space used due to recursion.


template <typename T>
void insertAtBottom(stack <T> &s, int num){

    if(s.empty()){

        s.push(num);
        return ;
    }

    int element = s.top();
    s.pop();

    insertAtBottom(s,num);

    s.push(element);

}

template <typename T>
void solve(stack <T> &s, int sz){

    //base case
    if(s.empty()){
        return;
    }

    T num = s.top();
    s.pop();
    solve(s, sz);

//---------------     YOU CAN ALSO CALL A FUNCTION WHILE BACKTRACKING DAMNN ITS TOO MUCH RECURSION !!!-----------------------------------------------------------------------
    insertAtBottom(s,num);// he gave it from the approach

}

template <typename T>
void stackRevRec(stack <T> &s){

    solve(s, s.size());

}


int main(){

    stack <int> s;
    int num = 12345;
    pushStackInt(s,num);
    printStack(s);
    stackRevRec(s);
    printStack(s);

    stack <char> ss;
    string str = "LIVE";
    pushStackStr(ss,str);
    printStack(ss);
    stackRevRec(ss);
    printStack(ss);


}