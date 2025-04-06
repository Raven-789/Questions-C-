#include<iostream>
#include<set>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){
    set <int>s;//this container doesn't allows duplicate values
    //In unordered set doesn't prints in ascending order
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(1);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    set <int> ::iterator it =s.begin(); //starts from begin

    s.erase(it);

    for (auto i : s)
    {
        cout<<i<<" ";
    }cout<<endl;
    
    cout<<"-5 is present or not: "<<s.count(-5)<<endl;

    set <int> ::iterator itr=s.find(5);
    
    for (auto it = itr ; it != s.end(); it++)
    {
        cout<<*it<<" ";
    }cout<<endl;
    
    

}