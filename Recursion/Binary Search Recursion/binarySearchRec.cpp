#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
    int mid=s+(e-s)/2;
    
    if(s>e)
        return 0;
    if(k==arr[mid])
        return 1;
    if(k>arr[mid])
        return binarySearch(arr,mid+1,e,k);

    if(k<arr[mid]) 
        return binarySearch(arr,s,mid-1,k);
    
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    cout<<binarySearch(arr,0,6,9);
}