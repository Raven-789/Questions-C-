// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each
//  integer appears at most twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding 
// the space needed to store the output

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []


#include<iostream>
#include<vector>
#include <bits/stdc++.h> //For sort function

using namespace std;


//Brute force
void find_Duplicates_Brute(vector<int> &arr){
    vector<int>ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i]!=arr[j]) continue;
            else{
                ans.push_back(arr[i]);
            }
        }
        
    }
    for (int k = 0; k < ans.size(); k++)
    {
        cout<<ans[k];
    }
}

//Sorting Method--------------------------------------------------------------------------------------------------------------------
void find_Duplicates_Sorting(vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==arr[i+1])
        {
            ans.push_back(arr[i]);
            i++;// So that index skips the next elements as its a repeat so its faster
        }
    }
    for (int k = 0; k < ans.size(); k++)
    {
        cout<<ans[k];
    }
}

//Updating the Array Method
void find_Duplicates_Update(vector<int>arr){
    vector <int>ans;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<abs(arr[i])<<"-----"<<arr[abs(arr[i])-1]<<"----   ";
        if (arr[abs(arr[i])-1]<0)
        {
            ans.push_back(abs(arr[i]));
            continue;
        }
        cout<< arr[abs(arr[i])-1]*-1<<endl; 
        arr[abs(arr[i])-1]*=-1; //we're using actual values of the array as the index values then making them -ve 
        //and updating the value with the -ve value so that when the repeated value occurs IT'LL GO TO THE SAME
        // VALUE WHICH IS NOW -VE AND BOOOM we've found the repeated element
    }
    
    
}

int main(){
    vector<int> arr1={4,3,2,7,8,2,3,1};
    find_Duplicates_Update(arr1);//Faster
    find_Duplicates_Sorting(arr1);//Fast
    find_Duplicates_Brute(arr1);//Slower
    //... the fastest one is Hash Map which will come I think later if you remember it that is!!
}