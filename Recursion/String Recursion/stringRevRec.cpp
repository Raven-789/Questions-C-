#include<iostream>
using namespace std;

// //With 2 variables
// string charRev(string &str,int s, int e){
//     if(s<=e){
//         swap(str[s++],str[e--]);
//         return charRev(str,s,e);
//     }
//     return str;
// }

//With one variable
string charRev(string &str, int s){
    if(s<str.size()-1-s){
        swap(str[s++],str[str.size()-s-1]);
        return charRev(str,s);
    }
    return str;
}

int main(){
    string str="evil";
    cout<<charRev(str,0);
}