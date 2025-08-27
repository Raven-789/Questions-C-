#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

//I saw his approach (I just saw it once it was easy soo I don't think it matteers but see it carefully) 
//Time Complexity O(n)
//Space Compelxity O(1)
template <typename T>
void printqueue(queue <T> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<< "ok" <<endl;

}

template <typename T>
void firstKElementsOfQueue(queue <T> &q, int k){

    stack <int> s;
    int sz = q.size();

    //pushing the elements of q till k into stack
    for(int i = 0; i < k; i++){

        s.push(q.front());
        q.pop();

    }

    //putting the elements in reverse order into queue from rear
    //while(!s.empty()){ // he used thsi one ok
    for(int i = 0; i < k; i++){

        q.push(s.top());
        s.pop();

    }

    // he used this instead of for loop
    // int t = sz - k
    //while(t--){
    for(int i = 0; i < (sz - k) ; i++){

        int ele = q.front();
        q.pop();
        q.push(ele);

    }

}

int main(){

    queue <int> q ;
    
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    
    //2nd input
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    printqueue(q);
    firstKElementsOfQueue(q, 4);
    printqueue(q);

}