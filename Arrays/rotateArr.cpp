#include<iostream>
#include<vector>
using namespace std;

void rotate(vector <int> &arr,int k){
    vector <int>temp(arr.size());

    for (int i = 0; i <arr.size() ; i++)
    {
        temp[(i+k)%arr.size()]=arr[i]; //this formula apparently gives index for rotated array where k 
                                         //is rotation n is total size
    }
    
    arr=temp;
}

void print(vector <int> arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    vector <int> arr={1,2,3,4,5,6,7};
    rotate(arr,3);
    print(arr);
}