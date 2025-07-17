#include<iostream>
using namespace std;

//merge sort by coping arrays

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void print(int arr[],int n){
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// merge sort using indexes my way (its simple too)
void mergee(int *arr, int s, int e){

    
    // int mid = (s+e)/2;
    // int temp;
    // // int len1 = mid - s + 1;
    // int len1 = mid;
    // // int len2 = e - mid;
    // int len2 = e ;
    // int mainArrayIndex = s;
    // // int index1 = 0;
    // int index1 = s;
    // int index2 = mid+1;

    for(int i = s ; i <= e ; i++){
        for(int j = s; j <= e ; j++){
            if(arr[i] < arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }

    // while(index1 <= len1 && index2 <= len2) {
    //     if(arr[index1] > arr[index2]) {
    //         swap(arr[index1++], arr[index2]);
    //     }else{
    //         index2++;
    //     }
    // }


    // while(index1 <= len1 && index2 <= len2) {
    //     if(arr[index1] < arr[index2]) {
    //         // arr[mainArrayIndex++] = arr[index1++];
    //         swap(arr[index1++], arr[index2++]);
    //         mainArrayIndex++;
    //     }
    //     else{
    //         // arr[mainArrayIndex++] = arr[index2++];
    //         swap( arr[index2++] ,arr[index1++]);
    //         mainArrayIndex++;
    //     }
    // }   

    // while(index1 <= len1) {
    //     // arr[mainArrayIndex++] = arr[index1++];
    //     swap(arr[mainArrayIndex++] , arr[index1++]);
    // }

    // while(index2 <= len2 ) {
    //     // arr[mainArrayIndex++] = arr[index2++];
    //     swap(arr[mainArrayIndex++] , arr[index2++]);
    // }

    print(arr,e);
}

// this one is just for understanding its innplace sort but complicated unnecessarily so you can check it out on GFG too just search inplace merge sort
// void merge(int arr[], int start, int mid, int end){
//     int start2 = mid + 1;

//     // If the direct merge is already sorted
//     if (arr[mid] <= arr[start2]) {
//         return;
//     }
//     // Two pointers to maintain start
//     // of both arrays to merge
//     while (start <= mid && start2 <= end) {

//         // If element 1 is in right place
//         if (arr[start] <= arr[start2]) {
//             start++;
//         }
//         else {
//             int value = arr[start2];
//             int index = start2;

//             // Shift all the elements between element 1
//             // element 2, right by 1.
//             while (index != start) {
//                 arr[index] = arr[index - 1];
//                 index--;
//             }
//             arr[start] = value;

//             // Update all the pointers
//             start++;
//             mid++;
//             start2++;
//         }
//     }
// }
// ------------------------------------------------------------------------------------------------------------------------------------------------------------


void mergeeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeeSort(arr, mid+1, e);

    //merge
    mergee(arr, s, e);

}

int main(){
    // int arr[]={38,27,3,3,9,82,10};
    // int arr[]={1,4,13,2,723,1,7,138,3};
    int arr[]={3,7,0,1,5,8,3};
    int n=7;
    // mergeSort(arr,0,n-1);
    mergeeSort(arr,0,n-1);

    cout<<"Sorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}