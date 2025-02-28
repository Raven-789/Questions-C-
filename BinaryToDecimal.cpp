#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    float ans=0; // use float as beacuse of precision issues the no. maybe different okay for pow funciton
    int i=0;
    while (n!=0)
    {
        // float bit =n%10;
        float bit =n&1;
        // bit= ;
        float p=pow(10,i);
        // cout<<pow(10,i)<<endl;
        ans=(bit * p)+ans; //This is used to reverse a DIGIT NOT A NUMBER in order for number you can mod and use ans=(mod*10)+ans
        
        cout<<ans<<endl;
        n=n >> 1;   
        i++;
    }
    cout<<"Answer is "<<ans<<endl;

}