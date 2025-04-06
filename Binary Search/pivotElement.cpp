//Okay so the pivot element question on Leetcode had another constraints which can't be solved through binary search


//But for curiosity if you want to know that question's problem statement its here
// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11


//so the question which was solved here is 
//here Pviot element is the one which is pivot for the arrays's flow in value okay like {3,8,10,17,1} in this array vals are just rotated 
//so by value the Pivot element here is 1 okay at index 4
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

int main(){
    // vector<int>arr={1,7,3,6,5,6}; //this the array for Leetcode's problem statement
    vector<int>arr={3,8,10,17,1};
    cout<<pivotElement(arr)<<endl;
    
}