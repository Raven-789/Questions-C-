#include<iostream>
using namespace std;

int maxSum(int arr[],int n,int k){
    int windowSum=0,maxSum=0;

    for (int i = 0; i < k; i++)
    {
        windowSum+=arr[i];
    }

    maxSum=windowSum;

    for (int i = k; i < n; i++)
    {
        windowSum+=arr[i]-arr[i-k];
        maxSum=max(maxSum,windowSum);
    }
    
    return maxSum;
}

int main(){
    int arr[]={2,1,5,1,3,2};
    int k=3;
    int n=6;
    cout<<maxSum(arr,n,k);
}