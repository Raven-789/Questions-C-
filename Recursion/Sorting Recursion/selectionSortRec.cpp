#include<iostream>
#include<vector>
using namespace std;

void printt(vector <int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

void selectionSort(vector <int> &arr,int n, int minIndex, int itrI, int itrrI, int itrJ){
    if(itrI == 0){
        itrrI=itrI+1;
    }

    if(itrI < n-1){
        if(minIndex == 0 || itrI == itrrI){
            minIndex = itrI;
        }
        if(itrJ==0 || itrI == itrrI){
            itrJ = itrI+1;
        }
        if(itrI==itrrI ){
                itrrI++;
        }
        if(itrJ < n){
            int j=arr[itrJ],i=arr[minIndex];
            if(arr[itrJ] < arr[minIndex]){
                minIndex=itrJ;
            }
            itrJ++;
            return selectionSort(arr,n,minIndex,itrI,itrrI,itrJ);
        }
        swap(arr[minIndex],arr[itrI]);
        // printt(arr);
        // cout<<endl;
        itrI++;
        return selectionSort(arr,n,minIndex,itrI,itrrI,itrJ);
    }
}

// void sort(int[] arr , int idx , int size)
//     {
//         //base case
//         if(idx == size)
//             return;

//         int smallestIdx = idx; // take curr idx element as smallest

//         for(int i = idx + 1; i < size; i++){
//             if(arr[smallestIdx] > arr[i]) // found another smallest element than arr[smallestIdx]
//                 smallestIdx = i; // update the smallestIdx val
//         }

//         //place smallest element found at idx
//         int temp = arr[idx];
//         arr[idx] = arr[smallestIdx];
//         arr[smallestIdx] = temp;

//         // one part Done recursion will do other work;
//         sort(arr , idx + 1 , size); 
// }



int main(){
    // vector <int> arr={89,34,5,79,54,15,43};
    vector <int> arr={78,43,22,45,677,8,64,33,33};
    selectionSort(arr,arr.size(),0,0,0,0);
    printt(arr);


    // int arr[7]={89,34,5,79,54,15,43};
    // selectionSort(arr,7);
    
    
    
}