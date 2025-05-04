#include<iostream>
#include<vector>
using namespace std;

//LPS LONGEST PREFIX SUFFIX
//Preprocess pattern to build LPS array

void computeLPS(string pattern , vector <int>&lps){
    int length=0;
    lps[0]=0;
    int i=1;

    while(i<pattern.length()){
        if(pattern[i]==pattern[length]){
            lps[i++]=++length;
        }else{
            if(length!=0){
                length=lps[length-1];
            }else{
                lps[i++]=0;
            }
        }
    }
}

//KMP Pattern Search
void KMPSearch(string text, string pattern){
    int n=text.length();
    int m=pattern.length();
    vector <int> lps(m);

    computeLPS(pattern,lps);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
}

int main(){
    string text , pattern;
    cout<<"Enter the text: ";
    getline(cin,text);
    cout<<"Enter the pattern; ";
    getline(cin,pattern);
    KMPSearch(text,pattern);
}