#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isAnagram(string a ,string b){
    if(a.length()!=b.length()) return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return (a==b);

}

int main(){
    string a,b;
    cout<<"Enter first word: ";
    cin>>a;
    cout<<"Enter second word: ";
    cin>>b;
    (isAnagram(a,b))?cout<< "It is Anagram!!" :cout<<"Its not an Anagram!!";
   
    
}