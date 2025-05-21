#include<iostream>
using namespace std;

//merge sort by coping arrays

int merge(int *arr, int s, int e, int inv) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    // bool ind1=0;
    // bool ind2=0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {


        if(first[index1] <= second[index2]) {
            // if(index1 != mainArrayIndex){
            //     inv++;
            // }
            arr[mainArrayIndex++] = first[index1++];
            // ind1=1;
            // inv=inv+(mainArrayIndex -(index1++ + mainArrayIndex));
            // mainArrayIndex++;
        }
        else{
            // if(index2 != mainArrayIndex){
            //     inv++;
            // }
            arr[mainArrayIndex++] = second[index2++];
            // ind2=1;
            // inv++;
            // mainArrayIndex++;index2++;
            // inv=inv+((index2++ +mid+1) - mainArrayIndex++ ); 
            
            if(len1>len2 && index1==0){
                inv += (len2-0)*(len1);
            }
            else if(index1==0){
                inv += (len2-0)*(index1+1);// I'm subtracting 0 cause' then that means all elements in first array are smaller in the other array as both are sorted think about it a little
            } 
            else{
                // inv += len2-((index2-1)*index1);
                inv += len1-(index1); // don't +1 as then they'll become equal and we don't want to count the end points just the middle in one case and it'll always be 1 ahead ok
            }
        }

        // if(ind1==1){
        //     inv=(mainArrayIndex-1+1)-(index1-1+1);// +1 is done cause' I'm doing the counting for inversion here & it starts from 1 not 0 like array and -1 is to equilize the increment of index so that I can get the original val of index before it was incremented
        // }else if(ind2==1){
        //     inv=(mainArrayIndex-1+1)-(index2-1+1);
        // }

        // ind1=ind2=0;


    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
        // inv=(mainArrayIndex-1+1)-(index1-1+1);
        // inv=inv+(mainArrayIndex++ -index1++);
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
        // inv=(mainArrayIndex-1+1)-(index2-1+1);
        // inv=inv+(mainArrayIndex++ - (index2++ +mid));
    }

    

    delete []first;
    delete []second;
    return inv;
}

int mergeSort(int *arr, int s, int e, int & inv) {

    //base case
    if(s >= e) {
        return 0;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid,inv);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e,inv);

    //merge
    // return merge(arr, s, e,inv);
    inv += merge(arr, s, e,0);

    return inv;
}

int main(){
    // int arr[]={38,27,3,3,9,82,10};
    // int arr[]={1,4,13,2,723,1,7,138,3};
    // int arr[]={3,7,0,1,5,8,3};
    //        {0,1,3,7,3,5,8}
    int arr[]={1,3,5,10,2,6,8,9}; 
    // int arr[] = {4, 3, 2, 1};
    int n=8, inv=0;
    // mergeSort(arr,0,n-1);
    cout<<mergeSort(arr,0,n-1, inv)<<endl;

    // cout<<inv;
    cout<<"Sorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}