//Used when the size of arrays or lists are small and space is a constraint 
//Space Complexity O(1)
//Time Complexity O(n^2)

#include<iostream>
#include<vector>
using namespace std;
void secletionSort(vector <int> &arr,int n){
    
    for (int i = 0; i < n-1; i++)
    {
        //we need a temp index no. so that we can replace even the same element technically for
        // the method of selection sort as it works that way
        //it sorts the smallest element first
        int minIndex=i;
        for (int j = i+1; j < n ; j++)
        {
            if (arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

}

void print(vector <int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}



int main(){
    vector <int> arr={89,34,5,79,54,15,43};
    secletionSort(arr,arr.size());
    print(arr);
    // int arr[7]={89,34,5,79,54,15,43};
    // secletionSort(arr,7);
    
    
    
}