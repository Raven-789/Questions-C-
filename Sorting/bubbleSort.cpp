//Timpe Complexity O(n^2)
//Space Complexity O(1)

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector <int> &arr,int n){
    for (int i = 1; i < n; i++)//we're starting it from 1 because we need that frist element to be compared with second one in j Loop
    {
        for (int j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])//sorting the largest element first then secondly 2nd largest
            {
                swap(arr[j],arr[j+1]);
            }
            
        }
        
    }
    
}

void print(vector <int>arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector <int>arr={8,9,4,56,7,3,2,1};
    bubbleSort(arr,arr.size());
    print(arr);
    
}