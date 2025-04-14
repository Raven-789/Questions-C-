#include<iostream>
using namespace std;

string replaceSpaces(string &str){
    string temp="";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]==' ')
        {
            // temp.replace(i,1,"@40"); //you can use this one for when you don't wanna have a tmep string simple
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(str[i]);
        }
        
    }
    return temp;
}

int main(){
    string s="I am gonna be the greatest!!!";
    cout<<replaceSpaces(s);
    
    
}