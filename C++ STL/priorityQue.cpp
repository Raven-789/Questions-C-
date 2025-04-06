#include<iostream>
#include<queue>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){
    //Max heap
    priority_queue <int> maxi;

    //Min Heap
    priority_queue <int,vector <int>,greater <int>> mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout<<"Size "<<maxi.size()<<endl;

    int n=maxi.size();

    // for (int i = 0; i < maxi.size(); i++) //we can't use this one as in there maxi.size chnages every interation
    for (int i = 0; i < n; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;
    

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);
    cout<<"Size "<<mini.size()<<endl;

    int m=mini.size();

    // for (int i = 0; i < mini.size(); i++) //we can't use this one as in there mini.size chnages every interation
    for (int i = 0; i < n; i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    cout<<"Empty or not: "<<mini.empty();// it'll be true as we're poping every element in the loop rememeber
    
}