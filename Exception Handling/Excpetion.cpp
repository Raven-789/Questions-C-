#include<iostream>
using namespace std;

int main(){
    try
    {
        int age =20;
        if (age>=18)
        {
            cout<<"Access granted - you are od enough";
        }else{
            throw(age);
        }
        
    }
    catch(int myNum)
    {
        cout<<"Access denied - yYou must be at least 18 years old.\n";
        cout<<"Your Age is : "<<myNum;
    }
    return 0;
}