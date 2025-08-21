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


// My Approach---------------------------------------------------------------------------------------------------------------------
// void insertAtBottom(stack <int> &s, int num){

//     if(s.empty()){

//         s.push(num);
//         return ;
//     }

//     int digit = s.top();
//     s.pop();

//     insertAtBottom(s,num);

//     s.push(digit);

// }


// if you've to return a value then use this and you made A MISTAKE HERE SOOO SEE IT
stack<int> insertAtBottom2nd(stack<int> s, int num) {
    if (s.empty()) {
        s.push(num);
        return s;
    }

    int digit = s.top();
    s.pop();

    s = insertAtBottom2nd(s, num);  // ← capture the returned value

    s.push(digit);
    return s;
}

int main(){

    stack <int> s;
    int num = 12345;
    pushStackInt(s, num);
    printStack(s);
    //In both my ways I've not used any extra stack okay
    // insertAtBottom(s,90);// my first way in which I'm making changes in the stack itself
    // printStack(s);
    printStack(insertAtBottom2nd(s,90));//my 2nd way in which I'm returning a value ok


}