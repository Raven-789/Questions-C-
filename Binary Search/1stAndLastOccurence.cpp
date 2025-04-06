//Something like pair is used in this question

// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.


// Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



// Note :
// 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. 'arr' may contain duplicate elements.


// Example:
// Input: 'arr' = [0,1,1,5] , 'k' = 1

// Output: 1 2

// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

#include<iostream>
#include<vector>
using namespace std;
int firstOccurence(vector<int>arr,int n, int key){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;

    while (s<=e)
    {
        if (arr[mid]==key)
        {
            ans=mid; // if mid is key then we'll search the lefter side as we need leftmost element
            e=mid-1; 
        }
        else if (key>arr[mid]) //if the mid is greater than we have to search the right half for the first element
        {
            s=mid+1;
        }
        else if (key<arr[mid])//the vice versa of previous condition
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
    return ans;
}

int lastOccurence(vector<int>arr,int n, int key){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;

    while (s<=e)
    {
        if (arr[mid]==key) 
        {
            ans=mid; //if mid is the key we'll search the righter side as we need the rightmost element
            s=mid+1;
        }
        else if (key>arr[mid])
        {
            s=mid+1;
        }
        else if (key<arr[mid])
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int>p;
    p.first=firstOccurence(arr,n,k);
    p.second=lastOccurence(arr,n,k);
    return p;
}


int main(){
    vector<int> arr={1,2,3,3,3,3,3,3,3,3,3,5};
    cout<<firstOccurence(arr,12,3)<<endl;
    cout<<lastOccurence(arr,12,3)<<endl;
    pair<int,int> x= firstAndLastPosition(arr,12,3);//Pair used 
    cout<<x.first<<endl<<x.second<<endl;
    //there is 1 more question which can be solved using this but its just slight difference in it
    //if you have to find no. of occurences of 3 in a SORTED ARRAY you can just subtract the 2 indexes which you 
    //got from this question's functions easily like this : - 
    cout<<"No. of occurrences of 3 is : "<<(x.second-x.first)+1<<endl;// you've to add 1 in the final answer as the 
                                                                        //indexes start form 0 so to equalize that 1 number
}