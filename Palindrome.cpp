#include <iostream>
using namespace std;

int main (){
    
    int s=0,r,n,temp;
    cout<<"Enter a number: ";
    cin>> n;
    temp=n;
    while (n>0)
    {
        r=n%10;
        s=s*10+r;
        n=n/10;
    }
    if(s==temp){
        cout<<"Palindrome"<<endl;
    }else if (s!=temp){
        cout<<"Not a Palindrome"<<endl;
    }
    return 0;
}