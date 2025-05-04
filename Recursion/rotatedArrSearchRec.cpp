#include<iostream>
#include<vector>
using namespace std;

int pivotElement(vector<int> arr,int s, int e, int mid){
    mid=s+(e-s)/2;
    if(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
            return pivotElement(arr,s,e,mid);
        }else{
            e=mid;
            return pivotElement(arr,s,e,mid);
        }
        mid=s+(e-s)/2;// its functioning fine even when its commented
    }
    return s;
}

int binarySearch(vector <int> arr,int s, int e, int k, int mid){
    mid=s+(e-s)/2;
    
    if(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        if(k>arr[mid]){
            s=mid+1;
            return binarySearch(arr,s,e,k,mid);
        }
        if(k<arr[mid]){
            e=mid-1;
            return binarySearch(arr,s,e,k,mid);
        }
    }
    return -1;
}

int findPosition(vector <int>arr,int n,int k){
    int pivot=pivotElement(arr,0,arr.size(),0);
    if ((k>=arr[pivot]) && (k<=arr[n-1]))
    {
        return binarySearch(arr,pivot,n-1,k,0);
    }
    else{
        return binarySearch(arr,0,pivot-1,k,0);
    }
}

int main(){
    vector <int> arr={12, 15, 18, 2, 4};
    // cout<<pivotElement(arr,0,arr.size(),0);
    cout<<findPosition(arr,arr.size(),2)<<endl;
}
