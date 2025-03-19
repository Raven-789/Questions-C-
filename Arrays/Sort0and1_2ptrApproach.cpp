//2 Pointer approach question
//Sorting of 0s and 1s

#include<iostream>
using namespace std;

void sortZero(int arr[],int size){
    int left=0, right=size-1;

    while (left<right){ //Do not put <= there it goes into infinite loop
        while ((arr[left]==0)&&(left<right))
        {
            left++;
        }

        
        
        while ((arr[right]==1)&&(left<right))
        {
            right--;
        }
        if (left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        
    }
    
}

void printarr(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[8]={1,1,0,0,0,0,1,0};
    sortZero(arr,8);
    printarr(arr,8);
    cout<<"yo";
}