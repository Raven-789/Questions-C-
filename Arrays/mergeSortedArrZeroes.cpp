#include<iostream>
#include<vector>
using namespace std;

void merge (vector <int> &arr1, int m,vector <int> &arr2,int n,vector<int> &arr3){
    int i=0,j=0,k=0;

    while (i<m && j<n)
    {
        if (arr2[j]!=0)
        {
            if (arr1[i]!=0)
            {
                
                if (arr1[i]<arr2[j])
                {
                    // arr3[k++]=arr1[i++];
                    arr3.push_back(arr1[i++]);
                }
                else{
                    // arr3[k++]=arr2[j++];
                    arr3.push_back(arr2[j++]);
                }    
            }else{
                i++;
            }
        }else{
            j++;
        }
    }

    while (i<m)
    {
        if (arr1[i]!=0){
            // arr3[k++]=arr1[i++];
            arr3.push_back(arr1[i++]);
        }else{
            i++;
        }
    }
    
    while (j<n)
    {
        if (arr2[j]!=0){
            // arr3[k++]=arr2[j++];
            arr3.push_back(arr2[j++]);
        }else{
            j++;
        }
    }
    
}

void print(vector <int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    vector <int> arr1={1,2,3,0,0,0,4};
    vector <int> arr2={2,5,6};

    vector <int> arr3;

    merge(arr1,arr1.size(),arr2,arr2.size(),arr3);

    print(arr3);
    
}