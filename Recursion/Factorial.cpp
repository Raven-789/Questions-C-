#include<iostream>
using namespace std;


int factorial(int n){
    if (n==0) 
        return 1; //Base Case
    // cout<<n*factorial(n-1);
    int smaller_problem=factorial(n-1);
    int bigger_problem=n*smaller_problem;
    return bigger_problem;
    
}

int main (){
    cout<<factorial(4);
}