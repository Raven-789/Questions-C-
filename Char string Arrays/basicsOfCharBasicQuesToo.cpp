#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getLenChar(char name[]){
    int count=0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void revChar(char name[],int l){
    int s=0,e=l-1;
    while (s<e)
    {
        swap(name[s++],name[e--]);
    }
    
}

char toLowerCase(char ch){
    if (ch>='a' && ch<='z')
    {
        return ch;
    }else{
        char temp=ch-'A'+'a'; //for ex: you subtract 64-65= 1 this onee is then added by 'a' which makes this 'b' simple you can do it with ASCII vel too if you want
        return temp;
    }
    
}

bool isPalindromeChar(char word[],int n){
    int s=0,e=n-1;

    while (s<e)
    {
        if (toLowerCase(word[s])!=toLowerCase( word[e])) //this lower case function has made it case Insensitive now
        {
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
} 


int main(){
    char name[20];
    string line;

    string namee="Cyber_hooks",emp="",s="Hello World!!";
    cout<<"Length: "<<namee.length()<<endl;

    cout<<"Size: "<<namee.size()<<endl; 

    cout<<"Empty or Not : "<<(emp.empty()?"Empty":"Not empty")<<endl;

    cout<<"Substring: "<<namee.substr(5,5)<<endl;

    cout<<"Find Function : "<<namee.find("hook")<<endl;

    cout<<"Find with starting no. : "<<s.find("o",5)<<endl;

    cout<<"Reverse Find (rfind()): "<<s.rfind("o")<<endl;

    string str1="abcc" ,str2="abcc",str3="abcdefg",str4="ab";

    cout<<"String compare: "<<endl;
    cout<<"String equal or same : "<<str1.compare(str2)<<endl;
    cout<<"1st string is less: "<<str1.compare(str3)<<endl;
    cout<<"1st is more: "<<str1.compare(str4)<<endl;

    cout<<"Append (you can put in a whole string in this but not in push back): "<<str1.append(str4)<<endl;

    cout<<"Insert: "<<str3.insert(4,str2)<<endl;

    cout<<"Erase: "<<str3.erase(3)<<endl;

    string er="abcdefghijklmnopqrstuvwxyz";

    cout<<"Erase: "<<er.erase(4,15)<<endl;

    cout<<"Replace (pos,len,new_str): "<<er.replace(0,3,"xyz")<<endl;

    string h="Hello";
    h.push_back('!');
    cout<<"Push Back: "<< h <<endl;

    h.pop_back();
    cout<<"Pop back: "<<h<<endl;


    cout<<"Enter full sentence: ";
    getline(cin,line);
    transform(line.begin(),line.end(),line.begin(),:: toupper);
    cout<<"Uppercase: "<<line<<endl;
    cout<<"Enter your name "<<endl;
    cin>>name;//Input of a char arr is simple you don't need to put every single element one by one
    // name[2]='\0';//null character
    //the char stops when null character , Space, Tab comes or New line character
    cout<<getLenChar(name)<<endl;
    cout<<"Your name is "<<name<<endl;
    int l=getLenChar(name);
    revChar(name,l);
    cout<<name<<endl;
    cout<<"Is Palindrome or not "<<isPalindromeChar(name,l)<<endl;
    cout<<"Character is "<<toLowerCase('A')<<endl;
    cout<<"Character is "<<toLowerCase('b')<<endl;
}