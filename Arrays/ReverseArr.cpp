#include<iostream>
using namespace std;
void rev(int arr[],int size){
    int temp=0;

    if (size%2==0)
    {
        for (int i = 0; i < (size/2); i++)
        {
            // int num=size-i-1;
            temp=arr[i];
            cout<<arr[i]<<"  "<<arr[size-1-i]<<endl;
            arr[i]=arr[size-i-1];
            arr[size-i-1]=temp;
            cout<<arr[i]<<"  "<<arr[size-i-1]<<endl;

        }
    }else{
        for (int i = 0; i < (size-1)/2; i++)
        {
            // int num=size-i;
            temp=arr[i];
            // cout<<arr[i]<<"  "<<arr[num]<<endl;
            arr[i]=arr[size-i-1];
            arr[size-i-1]=temp;
            cout<<arr[i]<<"  "<<arr[size-i-1]<<endl;
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

void print(int arr[],int size){
    cout<<"Reverse Array : -"<<endl;
    for (int i = 0; i < size; i++) 
    {
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    int arr1[7]={1,2,3,4,5,6,9};
    rev(arr1,7);
    revv(arr,5); //In size here we had to put the last index or first index value or it takes garbage value which
     //  gave an  error cause' you used arr[i+1] and at the last index or for 1st val too. it went garbage that's why
     print(arr1,7);
     print(arr,6);
    
    
}