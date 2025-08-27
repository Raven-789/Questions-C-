#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


//My Approach-----------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n)
//Space Complextiy O(n)


void interleave1stHalfOfQueueWith2ndHalf(queue <int> &q,int sz){

    // --------------------------------------------------------------------------------------------------------------------
    //you can do this question while using queue as auxiliary space but there was a constraint to use only STACK okk
    // --------------------------------------------------------------------------------------------------------------------
    stack <int> s1 ,s2;
    int n;


    for(int i = 0; i < sz/2; i++ ){
        s1.push(q.front());
        q.pop();
    }

    // if the size of queue is odd
    if((sz % 2) != 0){
        n = (sz+1)/2;
    }else{
        n = sz/2;
    }

    for(int i = 0; i < n; i++ ){
        s2.push(q.front());
        q.pop();
    }

    for(int i = 0; i < sz; i++){

        if(i == 0 || i % 2 == 0){
            q.push(s2.top());
            s2.pop();
        }else{
            q.push(s1.top());
            s1.pop();

        }

    }

    for(int i = 0; i < sz; i++){
        s1.push(q.front());
        q.pop();

    }
    cout<<s1.top()<<endl;

    for(int i = 0; i < sz; i++){
        q.push(s1.top());
        s1.pop();
    }

    // --------------------------------------------------------------------------------------------------------------------
    //you can do this question while using queue as auxiliary space but there was a constraint to use only STACK okk
    // --------------------------------------------------------------------------------------------------------------------

    return ;


}


//His Approach-----------------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n) better time tho
//Space Complextiy O(n) better space tooo

void interleave1stHalfOfQueueWith2ndHalfHis(queue <int> & q, int sz){

    stack <int> s;

    //putting 1st half of queue in stack
    for(int i = 0; i < sz/2; i++){

        s.push(q.front());
        q.pop();

    }

    //adding the elements of stack back to queue(now the 1st half is in rev order and behind the 2nd half)
    for(int i = 0; i < sz/2; i++){

        q.push(s.top());
        s.pop();

    }

    //putting the 2nd half behind the reversed 1st half 
    for(int i = 0; i < sz/2; i++){

        q.push(q.front());
        q.pop();

    }

    //putting 1st half of queue again in stack this'll give us right order of elements in stack

    for(int i = 0; i < sz/2; i++){

        s.push(q.front());
        q.pop();

    }

    while(!s.empty()){

        //first put the stack elemnt in the back
        int val1 = s.top();
        s.pop();
        q.push(val1);

        //then put the front element of the queue in the back  this way we get the interleaved order of elements (check it if you want to)
        int val2 = q.front();
        q.pop();
        q.push(val2);

    }

    cout<<q.front()<<endl;

}



int main(){

    queue <int > q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);

    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    // 20 15 19 14 18 13 17 12 16 11  (this is for reference ok its in reverse)
    
    int sz = q.size();

    // --------------------------------------------------------------------------------------------------------------------
    //you can do this question while using queue as auxiliary space but there was a constraint to use only STACK okk
    // --------------------------------------------------------------------------------------------------------------------
    // interleave1stHalfOfQueueWith2ndHalf(q,sz);//mine
    interleave1stHalfOfQueueWith2ndHalfHis(q,sz);//his

    for(int i = 0; i < sz; i++) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;


}