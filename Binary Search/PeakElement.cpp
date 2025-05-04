// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

// Return the index of the peak element.

// Your task is to solve it in O(log(n)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]

// Output: 1

// Example 2:

// Input: arr = [0,2,1,0]

// Output: 1

#include<iostream>
#include<vector>
using namespace std;
int peakElement(vector<int> arr){
    int s=0;
    int e=arr.size()-1;

    int mid=s+(e-s)/2;

    while (s<e)
    {
        if (arr[mid]<arr[mid+1])//you made a mistake here putting +1 outside square brackets
        {
            s=mid+1;
        }
        else 
        {
            e=mid; //we're making it mid only because mid-1 might include the peak element which we can't miss
        }
        mid=s+(e-s)/2;
        
    }
    return s;
}
 
int main(){
    vector <int>arr={0,1,0}; // I commented this so that I can put another vector with same name so not much editing in the existing code
    // vector <int>arr = {0,2,1,0};
    // vector <int>arr = {6,7,9,4,3,2,1};
    cout<<peakElement(arr)<<endl;
}