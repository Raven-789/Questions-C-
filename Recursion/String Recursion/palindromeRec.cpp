#include<iostream>
using namespace std;

bool palindrome(string &str,string str2,int s, int e){
    if(s<=e){
        swap(str[s++],str[e--]);
        return palindrome(str,str2,s,e);
    }
    // cout<<str;
    return (str==str2 );
}

int main(){
    // string str="madam";
    string str="abbccbba";
    cout<<palindrome(str,str,0,str.length()-1);
}