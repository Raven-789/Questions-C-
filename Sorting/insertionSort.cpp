//Its Adaptable Algo
//Its Stable
//Space Complexity O(1)
//Best Case Time Complexity O(n)
//Worst Case Time Complexity O(n^2)

#include<iostream>
#include<vector>
using namespace std;

void insertionSort( int arr[],int n){
    for (int i = 1 ; i < n; i++)
    {
        int temp=arr[i];
        int j = i-1;
        for (; j >= 0; j--)//we're comparing the ith index with previous ones 
        {
            if (arr[j]>temp)//if you change the sign it'll do descending order
            {
                arr[j+1]=arr[j];
                // swap(arr[j+1],arr[j]);
            }else{
                break; // its breaking here so that if the no. is greater that should be putted in that index
            }
        }

    arr[j+1]=temp;// this so the element j+1 doesn't repeat ok you can try to figure out by commenting it bn n
    }
    
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    // vector <int> arr={55,64,32,7,44,6,3};
    int arr[]={55,64,32,7,44,6,3};
    // insertionSort(arr,arr.size());
    insertionSort(arr,7);
    print(arr,7);
}
