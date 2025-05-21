#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector <int> arr ,int k, int mid, int cowcnt, int lastPos,int first, int itr, int maxi){

    if((first <= maxi && first > 0)|| k>=arr.size()){
        if(first-lastPos>=mid){
            cowcnt++;
            if(cowcnt==k){
                return true;
            }
            lastPos=first;
        }
        first=arr[0+itr++];
        return isPossible(arr, k, mid, cowcnt, lastPos, first, itr, maxi);
    }
    return false;
}

int cow(vector <int> arr,int sz ,int s ,int e ,int k, int ans ,int maxi){
    sort(arr.begin(),arr.end());
    int mid=s+(e-s)/2,itr=0;

    if(s<=e){
        if(isPossible(arr, k, mid, 1, arr[0],arr[0], itr,maxi)){
            ans=mid;
            s=mid+1;//going to the right part
            return cow(arr,arr.size(),s,e,k,ans,maxi);
        }else{
            e=mid-1;
            return cow(arr,arr.size(),s,e,k,ans,maxi);
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector <int> stalls={4,2,1,3,6};
    int maxi=-1;
    for(int i = 0 ; i < stalls.size() ; i++){
        maxi=max(stalls[i],maxi);
    }
    cout<<cow(stalls,5,0,maxi,4,0,maxi);
}