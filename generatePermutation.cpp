#include<iostream>
#include<vector>
using namespace std;

void generatePermutation(vector <int> &nums, int index, vector<vector <int>>& result){
    if(index == nums.size()){
        result.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); ++i){
        swap(nums[i],nums[index]);
        generatePermutation(nums,index+1,result);
        swap(nums[i],nums[index]);//backtrack
    }
}

int main (){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;

    generatePermutation(nums, 0, result); 

    cout << "All permutations:" << endl;
    for (auto perm : result) {
        cout << "[ ";
        for (int num : perm)
            cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}