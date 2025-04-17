#include<iostream>
using namespace std;

int modularExponentiation(int x,int n,int m){
    int res=1;

    while (n>0)
    {
        if (n&1)//to check its odd or not
        {
            res=(1LL *(res)* (x)%m)%m;
            n=n>>1;//right shift to divide it by 2
        }
        
    }
    return res;
}

int main(){
    cout<<modularExponentiation(3, 1, 2);
}