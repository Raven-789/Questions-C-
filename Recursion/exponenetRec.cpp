#include<iostream>
using namespace std;

int expo(int a,int b){
    if(b==1){
        return a;
    }
    if(b==0) return 1;

    int ans=expo(a,b/2);

    if(b&1){
        return a*(ans*ans);
    }else{
        return ans*ans;
    }
    
}

int main(){
    int a=3;
    int b=11;
    cout<<expo(a,b);
}