#include<iostream>
using namespace std;

int fibo(int f){
    
    
    // if (f==-1)
    // {
    //     // cout<<f;
    //     return 0;
    // }
    
    // cout<<f;
    // fibo(f-1);
    // if (f<=1)
    // {
    //     cout<<f<<" ";
    // }
    // else{
    //     cout<<
    // }
    if ((f==0)||(f==1))
    {
        return f;
    }else{
        return fibo(f-1)+fibo(f-2);
    }
}

int main(){
    //this gives that positioni's fibonnaci number
    cout<<fibo(5);
}