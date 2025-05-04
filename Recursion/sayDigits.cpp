#include<iostream>
using namespace std;

void sayDigits(int n){
    string number[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int dig=n%10;
    int quo=n/10;
    // if(quo>0 && dig==0){ 
    //     cout<<"Zero ";
    // }
    if(dig==0 &&quo==0)
    // if(dig==0)
        return ;
    sayDigits(quo);
    cout<<number[dig]<<" ";
}

void sayDigitt(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
    n = n / 10;
    

    //recursive call
    sayDigitt(n, arr);

    cout << arr[digit] << " ";

}

int main(){
    string arr[10] = {"zero", "one", "two", "three",
        "four", "five", "six"
       , "seven", "eight", "nine"};
    int n=390;
    // cout<<"Enter a number: ";
    // cin>>n;
    sayDigits(n);
    // sayDigitt(n,arr);
}