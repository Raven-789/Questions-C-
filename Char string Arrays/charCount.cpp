#include<iostream>
#include<string>
using namespace std;

char getMaxOccChar(string s){
    //to store every char's occurence
    int arr[26]={0};//use zero here

    for (int i = 0; i < s.length(); i++)
    {
        char ch=s[i];
        //lower case
        int number =0;
        if (ch>='a' && ch<='z')
        {
            number=ch-'a';
        }
        //upper case
        else{
            number=ch-'A';
        }
        arr[number]++;
    }

    //finding Max Occ
    int maxi =-1,ans=0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi<arr[i])
        {
            ans=i;
            maxi=arr[i];
        }
    }
    char finalAns='a'+ans;
    return finalAns;
    
}

char getMaxOccCharacter(string s) {

    int arr[26] = {0};


    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans;

}

int main(){
    string s="oo",ss;
    cout<<getMaxOccChar(s)<<endl;
    cout<<getMaxOccCharacter(s)<<endl;
    getline(cin,ss);//How to get sapce tab 
    cout<<ss;
    
}