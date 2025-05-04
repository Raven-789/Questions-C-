#include<iostream>
#include<vector>
using namespace std;

int peakElement(vector <int> arr, int s, int e, int mid){
    mid=s+(e-s)/2;
    if(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
            return peakElement(arr,s,e,mid);
        }else{
            e=mid;
            return peakElement(arr,s,e,mid);
        }
        mid=s+(e-s)/2;
    }
    return s;
}

int main(){
    // vector <int>arr = {6,7,9,4,3,2,1};
    // vector <int>arr = {0,2,1,0};
    vector <int>arr={0,1,4,3,3,0};
    cout<<peakElement(arr,0,arr.size()-1,0)<<endl;
}