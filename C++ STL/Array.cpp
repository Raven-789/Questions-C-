#include<iostream>
#include<array>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

int main(){

    int basic[3]={1,2,3};

    array<int,4> a={1,2,3,4};

    int size =a.size();

    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<endl;
    }

    cout<<"Element at 2nd index of 'a' array "<<a.at(2)<<endl;//to have Random Access

    cout<<"Empty or not "<<a.empty()<<endl;//Returns bool

    cout<<"First Element:"<<a.front()<<endl;

    cout<<"Last Element:"<<a.back()<<endl;

    

    

}