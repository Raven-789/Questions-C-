#include<iostream>
#include<stack>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){
    stack <string>s;

    s.push("Monkey");
    s.push("D.");
    s.push("Luffy");

    cout<<"Top element "<<s.top()<<endl;
    
    s.pop();
    cout<<"Top Element "<<s.top()<<endl;

    cout<<"Size of stack "<<s.size()<<endl;

    cout<<"Empty or not "<<s.empty()<<endl;
}