#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> arr,int s,int e,int k,int ans){
    // int s=0,e=n-1,ans=0;
    // int ans=0;
    int mid=s+(e-s)/2;

    if(s<e){
        if(arr[mid]==k){
            // e=mid-1;  
            ans=mid;
            return firstOccurence(arr,s,mid-1,k,ans);
        }
        if(arr[mid]<k){
            // e=mid-1;
            return firstOccurence(arr,s,mid-1,k,ans);
        }
        if(arr[mid]>k){
            // s=mid+1;
            return firstOccurence(arr,mid+1,e,k,ans);
        }
    }
    return ans;
}

int lastOccurence(vector<int> arr,int s,int e,int k,int ans){
    // int s=0,e=n-1,ans=0;
    // int ans=0;
    int mid=s+(e-s)/2;

    if(s<e){
        if(arr[mid]==k){
            // e=mid-1;  
            ans=mid;
            return firstOccurence(arr,mid+1,e,k,ans);
        }
        if(arr[mid]<k){
            // e=mid-1;
            return firstOccurence(arr,s,mid-1,k,ans);
        }
        if(arr[mid]>k){
            // s=mid+1;
            return firstOccurence(arr,mid+1,e,k,ans);
        }
    }
    return ans;
}

pair<int ,int> firstLastOcc(vector<int> arr,int s,int e,int k,int ans){
    pair<int,int>p;
    p.first=firstOccurence(arr,s,e,k,ans);
    p.second=lastOccurence(arr,s,e,k,ans);
    return p;
}

int main(){
    vector<int> arr={1,2,3,3,3,3,3,3,3,3,3,5};
    // cout<<firstOccurence(arr,0,12,3,0);
    // cout<<lastOccurence(arr,0,12,3,0);
    pair<int,int> x= firstLastOcc(arr,0,12,3,0);//Pair used 
    cout<<"First Occurence: "<<firstLastOcc(arr,0,12,3,0).first<<endl;
    cout<<"Last Occurence: "<<firstLastOcc(arr,0,12,3,0).second<<endl;
}