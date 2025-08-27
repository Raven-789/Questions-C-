#include <iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include<cstring>
using namespace std;

queue <int> queueRev(queue <int> q){

    stack <int> s;
    cout<<"Given Queue (from within the function): "<<endl;
    // for(auto ele : q){// you can't use for each loop on queues as it doesn't gives iterators
    while(!q.empty()){

        s.push(q.front());
        cout<<q.front()<<" ";
        q.pop();

    }
    cout<<endl;

    while(!s.empty()){

        q.push(s.top());
      //   cout<<s.top()<<" ";
        s.pop();

    }

    return q;
}


int main(){

    cout<<9/2;

}