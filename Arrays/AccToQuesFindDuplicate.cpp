//You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. 
// There is a single integer value that is present in the array twice. Your task is to find the duplicate integer
//  value present in the array.

// For example:

// Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
// Note :
// A duplicate number is always present in the given array.

#include<iostream>
#include<vector>
using namespace std;


//You can also do this question with brute force as in Occurences file

int findDuplicate(vector<int> &arr){
    int ans=0;
    
    //XOR ing all array's elements (this is kind off making all array's elements XOR , repeting element included
    //  so that when we XOR it with 1->N-1 the unique elements get 0 and then the duplicate one will remain at last)
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<ans<<"^"<<arr[i]<<"= ";
        ans=ans^arr[i];
        cout<<ans<<endl;
    }

    //XOR ing [1->N-1] its continous no.s that's why this loop cancels out unique elements okay
    for (int j = 0; j < arr.size(); j++)
    {
        cout<<ans<<"^"<<j<<"= ";
        ans=ans^j;
        cout<<ans<<endl;
    }
    
    return ans;
}



int main() {
    //vector is a dynamic sized array just know this much for now (if you haven't read about it)
    vector<int> arr = {1, 2, 3, 4, 2}; // Example array with a duplicates
   
    int duplicate = findDuplicate(arr);
    
    cout << "The duplicate element is: " << duplicate << endl;

    
}