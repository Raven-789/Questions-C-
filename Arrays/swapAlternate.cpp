#include<iostream>
using namespace std;
void swapAtlernate(int arr[],int size){
    int temp=0;
    // for (int i = 0; i < size; i++)
    for (int i = 0; i < size; i++)
    {   
        if (i+1<size)
        {
            cout<<arr[i]<<"  "<<arr[i+1]<<endl;
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            cout<<arr[i]<<"  "<<arr[i+1]<<endl;
        }
        i++;
    }
    
}

//Faster Swaper
void swapalternatee(int arr[],int size){
    int i=0;
    while (i<size)
    {
        swap(arr[i],arr[i+1]);
        i=i+2;
    }
    
}

void printarr(int arr[],int size){
    cout<<"Alternate Swapped Array : "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    int arr[5]={1,2,3,4,5};
    int arr1[6]={1,2,3,4,5,6};
    // cout<<"hello";
    // swapAtlernate(arr,5);//In size here we had to put the last index value or it takes garbage value which gave an 
                         // error cause' you used arr[i+1] and at the last index val. it went garbage that's why

    swapAtlernate(arr1,6);
    // swapalternatee(arr,4); //Faster one
    // swapalternatee(arr1,5);//Faster one
    // printarr(arr,5); ////But for printing use the actual size
    printarr(arr1,6);
    
}