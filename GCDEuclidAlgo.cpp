#include<iostream>
using namespace std;
//Another relation which can be used to solve questions 
    //  lcm(a,b) * gcd(a,b)
    // =(a*b)

int gcd(int a ,int b){
    if (a==0)
    {
        return b;
    }
    if (b==0)
    {
        return a;
    }
    
    while (a!=b)
    {
        if (a>b)
        {
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;

}

int main(){
    int a,b;
    cout<<"Enter the values of a and b"<< endl;
    cin>>a>>b;

    int ans=gcd(a,b);//this works on euclid's GCD algo
    //Another relation which can be used to solve questions 
    //  lcm(a,b) * gcd(a,b)
    // =(a*b)
    cout<<"The GCD of "<<a<<" & "<<b<<" is: "<<ans<<endl;
}