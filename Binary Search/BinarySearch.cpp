//Binary Search has log n complexity

#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start=0,end=size-1;
    // int mid=(start+end)/2;
    int mid=start+(end-start)/2; //this will not return an error when start & end are near int variable so we use maths

    while (start <= end)
    {
        if (arr[mid]==key)
        {
            return mid;
        }

        if (key>arr[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
       
        // mid=(start+end)/2;//this will return an error if the start and end are near limit of int variable so we use the other one above
        
    }
    return -1;
    
}

int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};
    cout<<binarySearch(even,6,12)<<endl;
    cout<<binarySearch(odd,5,3)<<endl;
}