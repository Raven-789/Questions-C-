// if we do find the root with brute force we'll have to check every no.'s square but as the series of no. 
//is monotonic so we can use binary search which will give us log n complexity
#include<iostream>
using namespace std;

int sqBinarySearch(int x){
    int s=0,e=x;
    int mid =s+(e-s)/2;
    int ans=-1;
    while (s<=e)
    {
        int square=mid*mid;

        if (square==x)
        {
            return mid;
        }
        if (square<x)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double morePrecision(int n,int precision, int tempsol){
    double factor =1 ;
    double ans=tempsol;

    for (int i = 0; i < precision; i++)
    {
        factor =factor/10;
        for (double j = ans; j*j <n ; j=j+factor)
        {
            ans=j;
        }
        
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int tempsol=sqBinarySearch(n); 
    cout<<"Answer is "<<morePrecision(n,3,tempsol)<<endl;//tempsol is the integer part of the no. whose precision we want
    // cout<<sqBinarySearch(25);
}