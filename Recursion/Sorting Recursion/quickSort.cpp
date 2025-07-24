#include<iostream>
using namespace std;
//Time complexity
// avg case O(log n)
// best case O(log n)
// worst case O(n²)

// Space complexity
// O(n)

// int partition(int arr[],int low,int high){
//     int pivot =arr[high];
//     int i=low-1;

//     for (int j=low ; j < high ; j++)
//     {
//         if (arr[j]<pivot)
//         {
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[high]);
//     return i+1;

// }

// void quickSort(int arr[],int low,int high){
//     if (low<high)
//     {
//         int pi=partition(arr,low,high);
//         quickSort(arr,low,pi-1);
//         quickSort(arr,pi+1,high);
//     }
    
// }















//HIS CODEE MINE IS BETTER YAAYYYY !!! (I THINK YOU KNOW)
//Sadly I'm not I'll be better next time I swear


// int partition( int arr[], int s, int e) {

//     int pivot = arr[s];

//     int cnt = 0;
//     for(int i = s+1; i<=e; i++) {
//         if(arr[i] <=pivot) {
//             cnt++;
//         }
//     }

//     //place pivot at right position
//     int pivotIndex = s + cnt;
//     swap(arr[pivotIndex], arr[s]);

//     //left and right wala part smbhal lete h 
//     int i = s, j = e;

//     while(i < pivotIndex && j > pivotIndex) {

//         while(arr[i] <= pivot) 
//         {
//             i++;
//         }

//         while(arr[j] > pivot) {
//             j--;
//         }

//         if(i < pivotIndex && j > pivotIndex) {
//             swap(arr[i++], arr[j--]);
//         }

//     }

//     return pivotIndex;

// }

// void quickSort(int arr[], int s, int e) {

//     //base case
//     if(s >= e) 
//         return ;

//     //partitioon karenfe
//     int p = partition(arr, s, e);

//     //left part sort karo
//     quickSort(arr, s, p-1);

//     //right wala part sort karo
//     quickSort(arr, p+1, e);

// }












//my code


void print(int arr[],int n){
        for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int partition(int arr[], int s, int e){
    int cnt=0,i=s,j=e;

    while(i<=e){    
        if(arr[s] > arr[i] && arr[s] != arr[i]){
            cnt++;
        }
        i++;
    }
    swap(arr[s],arr[cnt+s]);
    print(arr,e);
    i=s;
    while(i < cnt+s && j > cnt+s){ //I'm using AND as if I use OR then one pointer may've a garbage val which can spoil the code and also I have to add "start" to cnt so that the condition is read or else its not working ok
        if(arr[cnt+s] <= arr[i] && arr[cnt+s] > arr[j] && arr[i] != arr[j]){
            swap(arr[i++],arr[j--]);
        }
        // if(arr[cnt] < arr[])
        if(arr[cnt+s] > arr[i]){ //I've used the = for the edge case if the element is smallest
            i++;
        }

        //Imagine there are 2 repeated values like {12,4,6,6,3,3,5,6} there 2 types of repeating vals 2 & 6
        // if I just put "<" then what'll happen is that it'll count the equal vals too and decrement the j--
        //pointer which will create an undesireable result as if we look at the arr then we'll see that b/w 
        // two 6s 3,3,5 are stuck which will not get sorted so THAT'S WHY TO SORT THEM TOO I used <= here
        //I didn't use it on i pointer as then the cnt is decreased as at i pointer there always should be 
        // a val less than pivot which if we use ">=" on i pointer will result in an undesirable val too
        if(arr[cnt+s] <= arr[j]){
            j--;
        }
    }
    print(arr,e);
    return cnt+s;// YOU DID A MISTAKE HERE you didn't add s to cnt so the function called recursively infinitely don't do that ok
}



void quickSort(int arr[],int s, int e){
    if(s>=e){
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr,s,p-1);

    quickSort(arr,p+1,e);
}



int main(){
    // int arr[]={10,7,8,9,1,5};
    // int arr[]={3,1,4,5,2};
    // int arr[]={10,7,5,5,6,6,4,4,5,5};
    int arr[]={6,2,4,1};
    // int arr[]={5,5,4,4,5,5};
    int n=4;

    quickSort(arr,0,n-1);

    cout<<"Sorted Array using Quick Sort: "<<endl;
    print(arr,n-1);
    
}