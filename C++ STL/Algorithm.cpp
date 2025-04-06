#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector <int>v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6 "<<binary_search(v.begin(),v.end(),6)<<endl;


    //lower_bound(v.begin(),v.end(),6) gives us our iterator we minus v.begin in it to get our lower bound 
    cout<<"Lower Bound "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"Upper Bound "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

    int a=3;
    int b=5;

    cout<<"Max "<<max(a,b)<<endl;

    cout<<"Min "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a "<<a<<endl;

    string abcd="abcdefghijkl";
    cout<<"String before being reversed "<<abcd<<endl;
    reverse(abcd.begin(),abcd.end());
    cout<<"String reversed "<<abcd<<endl;

    cout<<"Before rotation: "<<endl;
    for (int i : v)
    {
        cout<<i<<" ";
    }cout<<endl;
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"After rotation: "<<endl;
    for (int i : v)
    {
        cout<<i<<" ";
    }
    

}