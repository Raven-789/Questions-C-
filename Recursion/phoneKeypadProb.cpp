#include<iostream>
#include<vector>
using namespace std;

// void solve(string str, int index,string out, vector <string>& ans,vector <string>mapping ){
//     if(index >= str.length()){
//         ans.push_back(out);
//         return;
//     }

//     //exclude
//     solve(str,index+1,out,ans,mapping);

//     //include
//     char element = str[index];
//     // int num = stoi(element); 
//     mapping[element];
//     out.push_back(element);
//     // cout<<out;
//     solve(str,index+1,out,ans,mapping);
// }

// vector <string> phoneKey(string str){
//     //string arr can't be converted some datatype issue check it out if you want
//     // string arr[]={{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
//     string map = "";
//     int num = stoi(str);
//     vector <string>arr={{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
//     for(int i = 0; i < str.length(); i++){
//         int rem = num % 10;
//         num = num/10;
//         for(int j = 0; j < 8; j++){
//             if(j==rem-2){ //to equilize the indexes (-2)
//                 // map.push_back(arr[j]);
//                 map += arr[j];
//                 break;
//             }
//         }
//     }
    
//     int index=0;
//     vector <string> ans;
//     string out ;
//     solve( str,index,out,ans,arr);
//     return ans;
    
// }

// Time complexity O(4^n) 

void solve (int index, string str, string out, vector <string>& ans, string map[]){
    if(index >= str.length()){
        ans.push_back(out);
        return;
    }

    int number = str[index] - '0'; //to get the integer equivalent
    string value = map[number];

    for(int i = 0; i < value.length(); i++){
        out.push_back(value[i]);
        solve(index+1,str,out,ans,map);
        out.pop_back();
    }
}

vector <string> phoneKey(string str){
    int index = 0;
    vector <string>  ans;
    if(str.length() == 0){
        return ans;
    }

    string out="";
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(index,str,out,ans,mapping);
    return ans;
}



int main(){
    string str = "23";

    // string arr[]={{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < )
    // }

    // int num = stoi(str);

    // cout<< num+3;
    // cout<<arr[1][2];

    phoneKey(str);

    for(auto subset : phoneKey(str)){
        cout<<"[ ";
        for(char str : subset){
            cout<<str<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"ok";

}