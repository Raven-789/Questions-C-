#include<iostream>
#include<basic_string.h>

// #include<stdio.h>
using namespace std;
int main(){
    int  f,l,i,nm,len=0,nm2,b=0,t=0,r;
    string n,r1;
    
    cout<<"Enter any number: ";
    cin>>n;
    // nm=n;
    // nm2=n;

    len=n.length();
    // while (nm>0)
    // {
    //     nm=nm/10;
    //     len=len+1;
    // }

    for ( i = 1; i<=(len/2); i++)
    {
        r=n[i];
        r1=n[len];
    
        // t=r+r1;
        cout<<t<<" ";
        b=b+1;
    }
    


}
