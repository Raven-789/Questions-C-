// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



// Now the array is rotated at some pivot point unknown to you.



// For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].



// Now, your task is to find the index at which ‘k’ is present in 'arr'.



// Note :
// 1. If ‘k’ is not present in 'arr', then print -1.
// 2. There are no duplicate elements present in 'arr'. 
// 3. 'arr' can be rotated only in the right direction.


// Example:
// Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2

// Output: 3

// Explanation:
// If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).

#include<iostream>
#include<vector>
using namespace std;

int pivotElement(vector<int> arr){
    //This code is similar to the Peak Element question so I copied it okay its same we're just comparing the mid val with 0th index val 
    //to check if its a pivot element you know if you want you can also do the Leet code version too if you want
    int s=0,e=arr.size()-1;
    int mid=s+(e-s)/2;
    

    while (s<e)
    {
        if (arr[mid]>=arr[0])// this is to check if the element is a pivot element by value okay aka just check thè condition you'll get it
        {
            s=mid+1;
        }
        else 
        {
            e=mid;
        }
        mid=s+(e-s)/2;
        
    }
    return s;
}

//I've modified this binary search as the prev. one had default start from 0 and end is size-1 I needed something more 
int binarySearch(vector<int> arr,int s, int e,int key){
    int start=s,end=e;
    // int mid=(start+end)/2;
    int mid=start+(end-start)/2; //this will not return an error when start & end are near int variable so we use maths

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
        // mid=(start+end)/2;//this will return an error if the start and end are near limit of int variable so we use the other one above
        
    }
    return -1;
    
}

int findPosition(vector <int>arr,int n,int k){
    int pivot=pivotElement(arr);
    if ((k>=arr[pivot]) && (k<=arr[n-1]))
    {
        return binarySearch(arr,pivot,n-1,k);
    }
    else{
        return binarySearch(arr,0,pivot-1,k);
    }
}

int main(){
    vector <int> arr={12, 15, 18, 2, 4};
    cout<<findPosition(arr,arr.size(),2)<<endl;
    //there is a HW goto the vid's this part
}