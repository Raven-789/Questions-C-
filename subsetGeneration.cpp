#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int index, vector <int> & nums,vector <int>&current, vector <vector <int>>& result){
    
    if(index == nums.size()){
        result.push_back(current);
        return;
    }

    //Exclude current element
    generateSubsets(index + 1 , nums, current, result);

    //Include current element
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, result);

    current.pop_back(); // backtrack
}

void generatesubsets(int index, vector <int> &nums, vector <int> &current,vector <vector <int>> &result){
    if (index == nums.size());
    {
        result.push_back(current);
        return;
    }

    generatesubsets(index + 1, nums, current, result);

    current.push_back(nums[index]);
    generatesubsets(index + 1, nums, current, result);
    
    current.pop_back();
    
}

int main(){
    vector <int> nums={1,2,3};

    vector <vector <int>> result;
    
    vector <int> current;

    generateSubsets(0,nums, current, result);


    cout<<"All subset: "<<endl;

    for(auto subset : result){
        cout<<"[ ";
        for(int num : subset)
            cout<<num<<" ";

        cout<<"]"<<endl;
    }


    // int a = 10;
    // int x = a++;
    // int y = ++a;
    // cout << a << " " << x << " " << y;

}