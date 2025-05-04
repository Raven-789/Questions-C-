#include<iostream>
using namespace std;

void naiveSearch(string text, string pattern){
    int n=text.length();
    int m=pattern.length();

    for(int i=0;i<=n;i++){
        int j=0;

        //Compare pattern with substring starting at i
        while(j<m && text[i+j]==pattern[j]){
            j++;
        }

        //if pattern is fully matched
        if(j==m){
            cout<<"Pattern found at index "<<i<<endl;
        }
    }
}

int main(){
    string text ,pattern;
    cout<<"Enter the manin text: ";
    getline(cin,text);
    cout<<"Enter the substring to check in the main string: ";
    getline(cin,pattern);

    naiveSearch(text,pattern);
}