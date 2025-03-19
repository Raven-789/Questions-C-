//2 point approach is used here
//in 2nd optimization we used 2 point approach as we use while loop and as we use i & j variables with ++or --
//instead of 2 for loops (i,j) and it had 3 conditions see it...
// maybe that's why its called 2 point approach maybe not sure okay!!
//(Not related to 2 point approach) like first we did 1st optimization and then we did 2nd optimiztion



//Question statement
// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order.
// You have to find the intersection of these two arrays.

// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Note :
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non-decreasing order.
// 3. The output should be in the order of elements that occur in the original arrays.
// 4. If there is no intersection present then return an empty array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 100
// 1 <= N, M <= 10^4
// 0 <= A[i] <= 10^5
// 0 <= B[i] <= 10^5

// Time Limit: 1 sec
// Sample Input 1 :
// 2
// 6 4
// 1 2 2 2 3 4
// 2 2 3 3
// 3 2
// 1 2 3
// 3 4  
// Sample Output 1 :
// 2 2 3
// 3


#include<iostream>
#include<vector>
using namespace std;

void find_Intersection(vector<int> arr,int n,vector<int> arr1,int m){
    vector <int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
    //--------------------------------------------------------------------------------------------------------------------------------------
            //1st Optimiztion as arrays are in non decreasing order so if the element which we're comparing is samller than the other we 
            // don't need to ckeck the other elements are going to be increasing further anyways
            if (arr[i]<arr1[j])
            {
                break;
            }
    //---------------------------------------------------------------------------------------------
            if (arr[i]==arr1[j])//checking if the no. is same in the both arrays
            {
                ans.push_back(arr[i]);
                arr1[j]=INT8_MIN;//thsi so that it doesn't get swapped again so we updated the array with a no. which is on the edge of the
                // linit and also in question it doesn't expect a -ve no. so the input is never -ve and it'll not get updated again next 
                //time in if condition
                break;
            }
            
        }
        
    }
    
    for (int k = 0; k < ans.size(); k++)
    {
        cout<<ans[k]<<endl;
    }
    
}

// 2nd Optimization (Fastest right now atleast)
void find_Intersection_Faster(vector<int> arr,int n,vector<int> arr1,int m){
    int i=0,j=0;
    vector<int> ans;
    while ((i<n)&&(j<m))
    {
        if (arr[i]==arr1[j]){
            ans.push_back(arr[i]);
            i++;j++;
        }
        else if (arr[i] < arr1[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for (int k = 0; k < ans.size(); k++)
    {
        cout<<ans[k]<<endl;
    }
}

int main(){
    // vector<int> arr1={11,22,13,54,67,88,65,34} ,arr2={13,44,88,90,45,34,66,77};
    vector<int> arr1={1, 2, 2, 2, 3, 4};
    vector<int> arr2={2 ,2 ,3 ,3};
    // find_Intersection(arr1,8,arr2,8);//Intersection with random input which it'll not work as we also made are code optimized for
                                            // non decreasing order of elements
    find_Intersection(arr1,6,arr2,4);//intersection with constrained input
    find_Intersection_Faster(arr1,6,arr2,4);//Optimized

}