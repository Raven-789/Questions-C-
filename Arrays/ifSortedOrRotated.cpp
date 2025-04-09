#include<iostream>
#include<vector>
using namespace std;

bool check(vector <int> &arr){
    int count =0;
    int n=arr.size();

    for (int i = 1; i < n; i++)
    {
        if (arr[i-1]>arr[i])//we're checking elements so that if they're sorted or not
        {
            count++;
        }
    }
    if (arr[n-1]>arr[0]) //this is to check the last element with the first one
        count++;
    
    return count<=1;//we've put <= instead of just == because of the case if all the elements of the array are equal
}

int main(){
    vector <int> nums={3,4,5,1,2};
    cout<<check(nums);
}