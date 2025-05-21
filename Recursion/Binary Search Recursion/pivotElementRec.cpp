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

int main(){

    //Ask her with pivot element too as this function is also used in that question too


    vector<int>arr={3,8,10,17,1};
    cout<<pivotElement(arr,0,arr.size(),0)<<endl;
}