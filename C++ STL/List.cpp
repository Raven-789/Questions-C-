#include<iostream>
#include<list>//this list is doubly linked list as that's the most used one in all of those lists okay
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;
int main(){
    //NO random access possible like in Vector , deque,array .We have to traverse every element
    list <int>l;

    l.push_back(1);
    l.push_front(2);

    list <int>n(l);//To copy a list 

    cout<<"Copied list: "<<endl;
    for (int i : n)
    {
        cout<<i<<" ";
    }cout<<endl;
    
    list <int>m(5,100);
    cout<<"Initialized list: "<<endl;
    for (int i : m)//In this loops rememebr to put the right container
    {
        cout<<i<<" ";
    }cout<<endl;


    cout<<"Original list: "<<endl;
    for (int i : l)
    {
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin()); //NO need to do +1 here as its a linked list like you used to in deque
    cout<<"After Erase"<<endl;
    for (int i : l)
    {
        cout<<i<<" ";
    }cout<<endl;

    cout<<"size of list "<<l.size()<<endl;
    
}