#include<iostream>
#include<map>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;
//search ,insert ,erase ,find ,count O(log n)
//hash table (red black) O(1)

int main(){
    //if there are 2 same keys it updates the value in it but 2 same keys can't be there
    //Its sorted acc to the int in it
    map <int,string> m;
    m[1]="Monkey";
    m[8]="Luffy";
    m[7]="D.";
    

    // m.insert({5,"bheem"});

    cout<<"Before Erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding -13: "<<m.count(-13)<<endl;
    m.erase(7);

    cout<<"After Erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    auto it=m.find(7);

    for (auto i = it; i != m.end(); i++)
    {
        cout<<(*i).first<<endl;
    }
    
}