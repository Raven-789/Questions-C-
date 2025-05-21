#include<iostream>
using namespace std;

int sqBinarySearch(int s, int e,int x, int mid, int ans, int sq){
    mid=s+(e-s)/2;

    if(s<=e){
        sq=mid*mid;

        if(sq==x){
            return mid;
        }
        if(sq<x){
            ans=mid;
            s=mid+1;
            return sqBinarySearch(s,e,x,mid,ans,sq);
        }
        else{
            e=mid-1;
            return sqBinarySearch(s,e,x,mid,ans,sq);
        }
    }
    return ans;
}

double morePrecision(int n,int prec, double ans, double factor,double itrI, double itrJ,double itrrI,double itrrJ){

    if(itrI<prec){
        if(itrI==itrrI){
            factor=factor/10;
            // itrrI+=1; this shouldn be resetted on line 35
        }
        // j should reset everytime j finishes its cycyle for the nested loop
        if(itrrJ==0 || itrI==itrrI){
            itrJ=ans;
            itrrI+=1;
        }

        if(itrJ*itrJ<n){
            
            ans=itrJ;
            // itrJ=ans;
            itrJ=itrJ+factor;
            itrrJ++;
            return morePrecision(n,prec,ans,factor,itrI,itrJ,itrrI,itrrJ);
        }

        itrI++;
        return morePrecision(n,prec,ans,factor,itrI,itrJ,itrrI,itrrJ);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int tempsol=sqBinarySearch(0,n,n,0,-1,0);
    // cout<<tempsol;
    cout<<"Answer is "<<morePrecision(n,3,tempsol,1,0,0,0,0)<<endl;
}