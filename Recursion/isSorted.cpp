#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int arr[],int sz){
    if(sz==0||sz==1)
        return 1;

    if(arr[0]>arr[1])
        return 0;
    bool remanant=isSorted(arr+1,sz-1);
    return remanant;
    
}

//this won't work in vector as vector can't be added and like vec+1 and size argument there doesn't fit in anywhere

int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<isSorted(arr,7);
}