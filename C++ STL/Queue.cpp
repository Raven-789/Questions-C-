#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include<queue>
using namespace std;

int main(){
    queue <string> q;

    q.push("Monkey");
    q.push("D.");
    q.push("Luffy");

    cout<<"Size before pop "<<q.size()<<endl;
    cout<<"First Element "<<q.front()<<endl;
    q.pop();
    cout<<"First Element (After pop) "<<q.front()<<endl;

    cout<<"Size after pop "<<q.size()<<endl;
}