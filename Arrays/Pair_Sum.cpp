#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(int arr[],int n,int target){
    int left=0,right=n-1;

    while (left<right)
    {
        int sum=arr[left]+arr[right];
        if (sum==target)
        {
            return true;
        }
        else if(sum<target)
        {
            left++;
        }
        else{
            right--;
        }
        
    }
    return false;
    
}

void pair_sum(vector<int> &arr,int s){
    vector <vector <int>>ans;
    for (int i = 0; i < arr.size(); i++){
        // if j loop starts from 0 it repeates the arrays so we start 1 after i
        for (int  j = i+1; j < arr.size(); j++){ 
            if (arr[i]+arr[j]==s){
                vector <int>temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }   
        }
    }
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"]"<<endl;
    }
}


int main(){
    vector<int>arr={1,2,3,4,5,0};
    pair_sum(arr,4);

    // pairSumm(arr,5);
    // for (const auto &pair : result) {
//     //     cout << "[" << pair[0] << ", " << pair[1] << "]" << endl;
//     // }

    int arr1[]={1,2,3,9,11};
    int target=10;
    int n=5;

    if (hasPairWithSum(arr1,n,target))
    {
        cout<<"Array has 2 no. with sum "<<target;
    }else{
        cout<<"No such pair found. ";
    }
    
}




