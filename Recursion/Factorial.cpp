#include<iostream>
using namespace std;


int factorial(int n){
    if (n==0) return 1; //Base Case
    // cout<<n*factorial(n-1);
    return n*factorial(n-1);
    
}

int main (){
    cout<<factorial(7);
}