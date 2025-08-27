#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


//You copied IT!!!!!
string firstNonRepeatingChar(string str){

    map<char, int> m;
    string ans = "";
    queue<char> q;
        
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        q.push(ch);
        m[ch]++;
        
        while(!q.empty()) {
            if(m[q.front()] > 1){
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;

}

int main(){

    string str = "aaabc";

    cout<<firstNonRepeatingChar(str);

}