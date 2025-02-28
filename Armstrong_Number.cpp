#include <iostream.h>
using namespace std ;
int main(){
    int n,c=0,r,temp;
    cout<< "Enter a number: ";
    cin>>n;
    temp=n;
    while (n>0)
    {
        r=n%10;
        c=c+(r*r*r);
        n=n/10;
    }
    if (c==temp)
    {
        cout<<"Armstrong number";
    }
    else 
        cout<<"Not Armstrong number";

}