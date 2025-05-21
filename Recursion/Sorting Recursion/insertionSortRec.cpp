#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector <int> &arr,int n, int itr){

    if(itr==n){
        return;
    }

    int temp=arr[itr];
    int j = itr-1;
    for (; j >= 0; j--)//we're comparing the ith index with previous ones 
    {
        if (arr[j]>temp)//if you change the sign it'll do descending order
        {
            // arr[j+1]=arr[j]; // if you use this it'll be universal but then swap will reduce the no. of lines
            swap(arr[j+1],arr[j]);
        }else{
            break;
        }
    }
    // arr[j+1]=temp;  
    itr++;
    return insertionSort(arr,n,itr);

}

void print(vector <int>&arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector <int> arr={55,64,32,7,44,6,3};
    insertionSort(arr,arr.size(),1);
    print(arr);
}