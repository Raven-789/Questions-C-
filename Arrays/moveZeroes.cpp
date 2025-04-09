#include<iostream>
using namespace std;

//we're shifting non-zero values to left

void moveZeroes(int arr[],int size){
    int nonZero=0;

    for (int j = 0; j < size ;j++)
    {
        if (arr[j]!=0)
        {
            swap(arr[j],arr[nonZero++]);
        }
        
    }
    
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[5]={0,1,0,3,12};
    moveZeroes(arr,5);
    print(arr,5);
}