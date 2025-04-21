#include <iostream>
using namespace std;

int kadane(int arr[], int n){
    int maxsum = arr[0];
    int currsum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currsum = max(arr[i],currsum + arr[i]);
        maxsum = max(maxsum,currsum);
        cout<<"";
    }
    return maxsum;
}

int main(){
    int arrx[] = {7,3,-8,-9,2,-1,6,9};
    cout << kadane(arrx,8);
    int arr[]={1,2,3,9,11};
    int arr1[5]={0};
    int n=5;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum =sum + arr[j];
        }
        // cout<<arr[i]<<endl;
        arr1[i] = sum;
        // cout <<endl<< sum << " ";
        sum = 0;
        
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         sum = sum + arr[j];
    //     }
    //     arr1[i] = sum;
    //     cout << sum << " ";  // Printing the cumulative sum
    //     sum = 0;  // Resetting sum for the next iteration
    // }


}