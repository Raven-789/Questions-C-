#include<iostream>
#include<stack>
using namespace std;

template <typename T>
// void printStack(stack <T> s){
//     T ans;
//     while(!(s.empty())){
//         T ch = s.top();
//         // ans.push_back(ch);
//         cout<<ch;
//         s.pop();
//     }
//     // cout<<ans<<endl;
//     cout<<"ok"<<endl;
// }

void printStack(stack<T> s) {
    bool chk =s.empty();
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "ok" << endl;
}

// void printStackInt(stack <int>)

void pushStackStr(stack <char> &s, string str){ // we made it void as we've used reference variable

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];
        s.push(ch);

    }
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

//My approach which is non recursive I didn't knew yarr------------------------------------------------------------------------------------------------------
// Time Complexity O(n)
//Space Complexity O(1)
stack <char> delMidOfStack(stack <char> s, int n){

    int mid;
    stack <char> ans;
    n = n+1;
    if(n&1){
        mid = (n/2)+1;
    }else{
    //we've done +1 in this too as we are traversing the stack while putting it in other stack (its a method see it)
    //  it does it from the back soo to get the mid which starts from the original left side we need to do a +1 
        mid = (n/2)+1;
    }

    for(int i = 0; i < n; i++){
        if(i != mid-1){
            ans.push(s.top());
        }
        s.pop();
        printStack(s);
    }
    return ans;
}

//His Approach which is recursively------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O()
//Space Compleixty O()

void solve(stack <int> &s, int cnt, int size){

    //base case
    if(cnt == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    solve(s, ++cnt,size);

    s.push(num);

}

void deleteMidStack(stack <int> & s, int N){

    int cnt = 0;
    solve(s, cnt, N);   

}




int main(){

    // string str = "123456789";// I did it in char rather than int as I didn't knew how to make that stack
    // stack <char> s;
    // pushStackStr(s,str);
    // printStack(delMidOfStack(s,8));// you give one element less as for the size ok as it was question's requirement

    //You made stack num logic for this one soo you can do the stack one do it when you're revising ok
    //if you want to you can use the push stack fucnction's  logic 
    stack <int> n;
    int num = 12345;
    pushStackInt(n,num);
    deleteMidStack(n,4);
    printStack(n);
    


}