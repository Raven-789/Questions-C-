#include<iostream>
#include<vector>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){
    vector <int>v;
    vector <int>a(5,1);//Initializes every element by 1
    for (int i:a)
    {
        cout<<i<<" ";

    }cout<<endl;

    vector <int> last(a);//To copy a vector into another one

    for (int i:last)
    {
        cout<<i<<" ";

    }cout<<endl;

    //Capacity is the amount of space assigned for the element
    //It works like array but when its Size gets filled its capacity doubles
    //When you clear() a vector its size becomes 0 but its capacity remains SAME
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity : "<<v.capacity()<<endl;
    cout<<"Size : "<<v.size()<<endl;

    cout<<"Element at 2nd Index "<<v.at(2)<<endl;

    cout<<"Front "<<v.front()<<endl;
    cout<<"Back "<<v.back()<<endl;

    cout<<"Before Pop: "<<endl;
    for (int i:v)
    {
        cout<<i<<" ";

    }cout<<endl;
    
    v.pop_back();

    cout<<"After Pop: "<<endl;

    for (int i:v)
    {
        cout<<i<<" ";

    }cout<<endl;

    cout<<"Before Clear Size: "<<v.size()<<endl;

    v.clear();
    cout<<"After Clear Size: "<<v.size()<<endl;

    cout<<"Max Size (This doesn't changes even after erase or pop it works for vector , Deque) "<<v.max_size()<<endl;

}