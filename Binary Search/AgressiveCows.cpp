#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector <int>stalls,int k,int mid){
    int cowCount=1;
    int lastPos=stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        //YOU DID A MISTAKE here you didn't subtract lastPos from stalls which gave the gratest element
        //(which we don't want obviously)
        if (stalls[i]-lastPos>=mid) //Its greater than equal to as we want the greatest distance
        {
            cowCount++;
            if (cowCount==k)
            {
                return true;
            }
            lastPos=stalls[i];  
        }
        
    }
    return false;
}

int aggressiveCows(vector <int>stalls,int k){
    int s=0,maxi=-1;
    sort(stalls.begin(),stalls.end());

    for (int i = 0; i < stalls.size(); i++)
    {
        maxi=max(maxi,stalls[i]);
    }
    int e=maxi;
    int ans=-1;
    int mid=s+(e-s)/2;

    while (s<=e)
    {
        if (isPossible(stalls,k,mid))
        {
            ans=mid;
            s=mid+1;//we are going to right part because we want the largest distance
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    
}



int main(){
    vector <int> stalls={4,2,1,3,6};
    cout<<aggressiveCows(stalls,4);
}