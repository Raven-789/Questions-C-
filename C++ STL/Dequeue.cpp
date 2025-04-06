#include<iostream>
#include<deque>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){
    deque <int> d;

    d.push_back(1);
    d.push_front(2);

    //MAX size is the amount of space assigned to deque its same before or after erase
    cout<<"Max Size (This doesn't changes even after erase or pop  it works for vector, deque) "<<d.max_size()<<endl;

    cout<<"First Index Element "<<d.at(1)<<endl;
    cout<<"front "<<d.front()<<endl;
    cout<<"back "<<d.back()<<endl;

    cout<<"Empty or not "<<d.empty()<<endl;

    cout<<"Before Erase "<<d.size()<<endl;
    d.erase(d.begin(),d.begin()+1);// you have to do +1 maybe cause of the index you know just a hunch
    cout<<"After Erase "<<d.size()<<endl;
    

    for (int i : d)
    {
        cout<<i<<" ";
    }
    
    d.pop_back();
    // you can also use "d.pop_front();"
    cout<<endl;

    for (int i : d)
    {
        cout<<i<<" "<<endl;
    }
    cout<<"Max Size (This doesn't changes even after erase or pop it works for vector, deque) "<<d.max_size()<<endl;    

}