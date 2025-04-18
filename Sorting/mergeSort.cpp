#include<iostream>
using namespace std;

void merge(int arr[],int l ,int m ,int r){
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i]=arr[l+i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j]=arr[m+1+j];
    }
    
    int i=0,j=0,k=l;

    while (i<n1 && j<n2)
    {
        arr[k++]=(L[i]<=R[j])?L[i++]:R[j++];
    }
    
    while (i<n1)
    {
        arr[k++]=L[i++];
    }
    
    while (j<n2)
    {
        arr[k++]=R[j++];
    }

}

void mergeSort(int arr[],int l , int r){
    if (l<r)
    {
        int m=(l+r)/2;

        //sort left and right halves
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
    
}

int main(){
    // int arr[]={38,27,3,3,9,82,10};
    int arr[]={1,4,13,2,723,1,7,138,3};
    int n=9;
    mergeSort(arr,0,n-1);

    cout<<"Sorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}