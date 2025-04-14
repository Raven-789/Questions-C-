#include<iostream>
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