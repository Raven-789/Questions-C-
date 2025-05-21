#include<iostream>
#include<vector>
using namespace std;

//Figure out line 20

bool isPossible(vector <int> arr,int stdcnt , int stu, int sz, int mid, int pageSum, int itr){
    if(itr<sz){
        if(pageSum+arr[itr]<=mid){
            pageSum+=arr[itr];
        }
        else{
            stdcnt++;
    
            if(stdcnt > stu || arr[itr] > mid){
                return false;
            }
            pageSum=arr[itr];
        }
        if (stdcnt>stu){ //Figure this out mf like its equal but it still works
            return false;
        }
        itr++;
        return isPossible(arr,stdcnt,stu,sz,mid,pageSum,itr);
    }
    
    return true;
}

int bookAllocator(vector <int> arr,int s, int e, int stu, int mid, int ans){
    mid=s+(e-s)/2;

    if(s<=e){
        if(isPossible(arr,1,stu,arr.size(),mid,0,0)){
            ans=mid;
            e=mid-1;
            return bookAllocator(arr,s, e ,stu, mid ,ans);
        }else{
            s=mid+1;
            return bookAllocator(arr,s, e ,stu, mid ,ans);
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    //figure out line 20
    vector <int> arr={10,20,30,40};
    int sum=0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum=sum+arr[i];
    }
    cout<<bookAllocator(arr,0,sum,2,0,-1);
}