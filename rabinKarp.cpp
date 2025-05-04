#include<iostream>
using namespace std;

void rabinKarp(string text,string pattern ,int prime =101){
    int n=text.length();
    int m=pattern.length();
    int d=256;
    int h=1;
    //the val of h would be "pow(d,m-1)%prime"

    for(int i=0;i<m-1;i++){
        h=h*d%prime;
    }
    int p=0,t=0;
    for(int i=0;i<m;i++){
        p=(d*p+pattern[i])%prime;
        t=(d*t+text[i])%prime;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            bool match=true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    match=false;
                    break;
                }
            }
            if(match)cout<<"pattern found at index : "<<i<<endl;
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%prime;
            if(t<0)t+=prime;
        }
    }
}

int main(){
    string text ,pattern;
    cout<<"Enter the manin text: ";
    getline(cin,text);
    cout<<"Enter the substring to check in the main string: ";
    getline(cin,pattern);

    rabinKarp(text,pattern);
}