#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector <int> slidingWindowMax(vector <int> &nums , int k){
    deque <int> dq;
    vector <int> result;

    for (int i = 0 ; i < nums.size() ; i++){
        //Remove out of window
        if(!dq.empty() && dq.front() <= i-k)  dq.pop_front();

        //Remove smaller values from back
        while(!dq.empty()&& nums[dq.back()]<nums[i])
            dq.pop_back();
        
        dq.push_back(i);

        //Add to result
        if(i >= k-1)
            result.push_back(nums[dq.front()]);        
    }

    return result;
}

int main(){
    vector <int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector <int> res =slidingWindowMax(nums,k);

    for(int x :res)
        cout<<x<<" ";
}