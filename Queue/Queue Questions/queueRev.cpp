#include <iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include<cstring>
using namespace std;


// 1st Approach-----------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(n)

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


//2nd Approach-----------------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complexity O(1) Betterrrr!!!

//Its similar to Stack rev also check that ouut ok(stack one was done first)
//queue rev is different as stack inserts from right and pops from right too
//and queue inserts from right and pops from left that's why they're different

template <typename T>
void queueRev2nd(queue <T> &q){

    if(q.empty()){
        return ;
    }

    T element = q.front();
    q.pop();

    queueRev2nd(q);
    
    q.push(element);

}



int main(){
    queue <int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    //--------------
    // q.push(1);
    // q.push(2);
    // q.push(3);



//    queue<int> reversed = queueRev(q);

//    cout<<"Reversed queue: "<<endl;
//    while(!reversed.empty()){

//       cout<<reversed.front()<<" ";
//       reversed.pop();

//     }

    queueRev2nd(q);//BETTER ONEE!!!!
    while(!q.empty()){

        cout<<q.front()<<" ";
        q.pop();
    }

}