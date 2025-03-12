#include<iostream>
using namespace std;
void rev(int arr[],int size){
    int temp=0;

    if (size%2==0)
    {
        for (int i = 0; i < (size/2); i++)
        {
            // int num=size-i;
            temp=arr[i];
            // cout<<arr[i]<<"  "<<arr[num]<<endl;
            arr[i]=arr[size-i];
            arr[size-i]=temp;
            cout<<arr[i]<<"  "<<arr[size-i]<<endl;

        }
    }else{
        for (int i = 0; i < (size-1)/2; i++)
        {
            temp=arr[i];
            arr[i]=arr[size-i];
            arr[size-i]=temp;
        }
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
}

//Faster rev

void revv(int arr[],int size){
    int start=0;
    int end=size;
    while (start<=end)
    {
        // Instead of this you can use the 3 variable method of swap too as in above function
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    int arr1[7]={1,2,3,4,5,6,9};
    // rev(arr,6);
    revv(arr,5); //In size here put the last index value or it takes garbage value which gives error
    cout<<"Reverse Array : -"<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}