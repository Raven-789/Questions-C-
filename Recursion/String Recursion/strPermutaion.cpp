#include<iostream>
#include<vector>
using namespace std;

// there another approach to explore in lecture 39


// return type will be void 
// vector< vector <int>> solve(int idx, vector <int> in, vector <int> out, vector <vector <int>> &ans){
void solve(int idx, vector <int> in, vector <int> out, vector <vector <int>> &ans,int itr){
    //base condition
    // if(idx>=itr){
        // itr++;
    if(idx>=in.size()-1){
    // if(idx>=in.size()){
        // cout<<"[";
        // for(int i = 0; i < in.size(); i++){
        //     cout<<out[i];
        // }cout<<"]"<<endl;

        ans.push_back(out);
        return;
    }
    int sz=in.size();
    // int element=in[idx];

    for(int i = idx; i < sz; i++){//you took the hint here to start i from idx
        
//XXXXXX vector <int> temp=in;// This was the problem XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        // if(idx==2 || i==0){
        //     itr=idx;
        // }
        swap(out[i],out[idx]);
        // out=temp;
        // itr++;
        
        solve(idx+1,in,out,ans,itr+1);
        swap(out[i],out[idx]);
        // itr--;
    }

}

vector <vector <int>> strPermutaion(vector <int> &nums){
    int index=0;
    vector <int> out = nums;
    vector <vector <int>> ans;
    solve(index,nums,out,ans,0);
    return ans;
}

int main(){
    vector <int> vec={1,2,3,4};
    int i=1;
    for(auto arr : strPermutaion(vec)){
        cout<<"[";
        for(auto nm : arr){
            cout<<nm;
        }
        cout<<"]"<<i++<<endl;
    }
}