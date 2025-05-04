#include<iostream>
using namespace std;

bool linearSearch(int arr[] , int sz , int k){
    if(sz==1||sz==0)
        return 0;
    
    if(arr[0]==k)
        return 1;

    int foundOrNot= linearSearch(arr+1,sz-1,k);
    return foundOrNot;
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<< (linearSearch(arr,7,6)?"Element Found":"Element Not Found");
}