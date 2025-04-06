#include<iostream>
using namespace std; 

void bwdcount(int x){
    if (x==0)
    {
        return ;
    }
    cout<<x<<" ";
    bwdcount(x-1);
    // cout<<x<<" ";
}

int main(){
    bwdcount(5);
}