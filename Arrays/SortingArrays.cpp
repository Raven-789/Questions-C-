//Second smallest ASC & DESC in this code okay

// #include<iostream>
// using namespace std;

// int main(){
//     int n,j;
//     string ch;
//     cout<<"Enter size of array: ";
//     cin>>n;
    

//     int* arr = new int[n],i,nm;
//     // int* arr[n],i;
    
// // to input elements in array
//     for ( i = 0; i <= n-1; i++)
//     {
//         cout<<"Enter element "<<i+1<<" of the array: ";
//         cin>>arr[i];  
//     }
//     cout<<endl;
// // to dispay the inputed array
//     // for(i=0;i<=n-1;i++)
//     // {
//     //     cout<<i+1<<" element of the array: ";
//     //     cout<<arr[i]<<endl;
//     // }

// // for asc or desc choice

//     cout<<"Which order do you want (asc/desc): ";
//     cin>>ch;

// // first is desc condition
// //                      [5,10,7,9]
//     if (ch=="desc" or ch=="Desc") 
//     {
//         for ( i = 0; i < n-1; i++)
//         {
//             for ( j = 0+(i+1); j < n; j++)
//             {
//                 if (arr[i]>arr[j])
//                 {}
//                 else if (arr[i]<arr[j])
//                 {
//                     nm=arr[i];
//                     arr[i]=arr[j];
//                     arr[j]=nm;
//                 }
//             }
//         }
//     }
//     else if (ch=="asc" or ch=="Asc")
//     {
//         for ( i = 0; i < n-1; i++)
//         {
//             for ( j = 0+(i+1); j < n; j++)
//             {
//                 if (arr[i]<arr[j])
//                 {}
//                 else if (arr[i]>arr[j])
//                 {
//                     nm=arr[i];
//                     arr[i]=arr[j];
//                     arr[j]=nm;
//                 }
//             }
//         }
//         }    

// if (ch=="Asc" or ch=="asc")
// {
//     cout<<"The Ascending Order is : "<<endl;
// }
// else if (ch=="Desc" or ch=="desc")
// {
//     cout<<"The Descending order is "<<endl;
// }

// for(i=0;i<=n-1;i++)
// {

    
//     cout<<i+1<<" element of the array: ";
//     cout<<arr[i]<<endl;
// }

// for ( i = 0; i <=1; i++)
// {
//         if (i==1 and (ch=="desc" or ch=="Desc") )
//     {
//         cout<<"The second largest number in array is: "<<arr[i]<<endl;
//     }
//     else if(i==1)
//     {
//         cout<<"The second smallest number in array is: "<<arr[i]<<endl;
//     }

// }

// }

//⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻


//sort the elements of ann array into descending order (this oen you've done before too above)------------------------------------------------------------------------------------------------------------------------------------------------    
    //WORK ON IT after assignments
    //Question 3 
    // int arrRandom[5]={65,67,23,45,78},temp=0;
    // for (int i = 0; i < sizeof(arrRandom)/sizeof(arrRandom[0]); i++)
    // {
    //     for (int j = i+1; j < 5; j++)
    //     {
    //         if (arrRandom[i]>=arrRandom[j])
    //         {
    //             temp=arrRandom[j];
    //             arrRandom[j]=arrRandom[i];
    //             arrRandom[i]=temp;
    //         }
            
    //     }
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arrRandom[i]<<"->";
    // }


//⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻
//Take 2 unsorted or sorted arrays (it doesn't matters as they're gonna be sorted in the final anyway so..)
// into a FUNCTION and combine them and create a sorted array

#include <iostream>
using namespace std;

void SortArrAsc(int arrRandomF[],int size){
    int temp=0;
    for (int i = 0; i < size ; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arrRandomF[i]>=arrRandomF[j])
            {
                temp=arrRandomF[j];
                arrRandomF[j]=arrRandomF[i];
                arrRandomF[i]=temp;
            }
            
        }
    }

    // for (int i = 0; i <size; i++)
    // {
    //     cout<<arrRandomF[i];
    // }
}

//-------------------------------------------------------------Question 4---------------------------------------------------------------------------

int main(){

    int arr1[]={6,7,8,9,34,33,55,45,6310},arr2[]={1,2,3,857,423,4,5};
    int sz1=sizeof(arr1)/sizeof(arr1[0]),sz2=sizeof(arr2)/sizeof(arr2[0]),i=0,j=0,k=0;
    int arrf[sz1+sz2];
   
    while (i<sz1)
    {
        arrf[k++]=arr1[i++];
    }
    while (j<sz2)
    {
        arrf[k++]=arr2[j++];
    }
    

    SortArrAsc(arrf,sz1+sz2);

    for (int i = 0; i < sz1+sz2; i++)
    {
        cout<<arrf[i]<<" ";
    }


}

// 2ND Way of previous function  -----------------------------------------------------------------------------------------

// #include<iostream>
// using namespace std;

// void mergeArr(int arr1[],int size1, int arr2[], int size2,int merged[]){
//     int i=0,j=0,k=0;

//     while (i<size1 && j<size2)
//     {
//         if (arr1[i]<arr2[j])
//         {
//             merged[k++]=arr1[i++];
//         }else{
//             merged[k++]=arr2[j++];
//         }
//     }

//     while (j<size2)
//     {
//         merged[k++]=arr2[j++];
//     }

//     while(i<size1){
//         merged[k++]=arr1[i++];
//     }
    
    
// }

// int main(){
//     int arr1[]={1,3,5,7,12,16},arr2[]={2,4,6,8};
//     int size1=sizeof(arr1)/sizeof(arr1[0]), size2=sizeof(arr2)/sizeof(arr2[0]);

//     int merged [size1+size2];

//     mergeArr(arr1,size1,arr2,size2,merged);

//     cout<<"Merged sorted array: ";
//     for (int i = 0; i < size1+size2; i++)
//     {
//         cout<<merged[i]<<" ";
//     }
    

// }
