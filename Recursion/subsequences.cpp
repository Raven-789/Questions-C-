#include <iostream>
#include <vector>
using namespace std;

//Dry run of subset code and arr+1 logic revise today and I'll do it with bitwise operators

void solve(int index,string str, string out, vector <string> & ans){
    if(index >= str.size()){
        ans.push_back(out);
        return;
    }

    //exclude
    solve(index+1,str,out,ans);

    //include
    char element = str[index];
    out.push_back(element);
    cout<<out;
    solve(index+1,str,out,ans);

}

vector <string> subsequence(string str){
    int index=0;
    string out = "";
    vector <string> ans;
    solve(index,str,out,ans);
    // for(auto subset : ans){
    //     cout<<"[ ";
    //     for(char str : subset)
    //         cout<<str<<" ";

    //     cout<<"]"<<endl;
    // }
    // cout<<"ok";

    return ans;
}

int main(){
    string str="ace";

    // subsequence(str);

        for(auto subset : subsequence(str)){
        cout<<"[ ";
        for(char str : subset)
            cout<<str<<" ";

        cout<<"]"<<endl;
    }
    cout<<"ok";
}