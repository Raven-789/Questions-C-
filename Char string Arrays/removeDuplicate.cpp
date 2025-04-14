#include<iostream>
using namespace std;        

bool isDuplicate(string &s){
    string temp="";
    
}

string removeAdjDuplicates(string &s){
    // string temp="",dup="";
    bool chk=1;
    int i=0;
    // for (int i = 0; i < s.length()-1; i++)
    while(i!=s.size())
    {
        // cout<<i<<endl;
        if (s[i]==s[i+1])
        {
            // int begin=i,end=i+1;
            s.erase(i,2);
            
            cout<<s<<" "<<s.length()<<endl;
            // cout<<s[i]<<endl;
            i=0;
            chk=0;
            
        }
        if (chk)
        {
            i++;
            
        }
        chk=1;
        
    }
     
    return s;
}

// string removeDuplicates(string s) {
//     string res;
    
//     for(char ch : s){
//         if(!res.empty() && res[res.size() - 1] == ch) res.pop_back();
//         else res+=ch;
//     }
//     return res;
// }

int main(){
    string s = "abbaca";
    cout<<removeAdjDuplicates(s);
}