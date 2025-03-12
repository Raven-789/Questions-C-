//Sorting arrays named file also has questions like these in which arrays are passed into the functions
//


//--------------------------------------------Passing Arrys to Functions-------------------------------------------------
// #include<iostream>
// using namespace std;

// void display(int arr[],int size){
//     for (int i = 0; i < size; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }

// int main(){
//     int nums[]={10,20,30,40,50};
//     display(nums ,5);


// }



//Question 6 create a fucntion to toake an array and gives the smallest element of the array
#include<iostream>
#include<stdint.h>
using namespace std;
int min(int arr[],int size){
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]>=arr[j])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
            
        }
    }
    return arr[0];
}

//Faster functions

int mini(int arr[],int size){
    int mini=__INT_MAX__;

    
    for (int i = 0; i < size; i++)
    {
        mini=min(mini,arr[i]); //Makes the min fuction even faster
    //     if (arr[i]<mini)
    //     {
    //         mini=arr[i];
        // }   
    }
    return mini;
}

int maxi(int arr[],int size){
    int maxi=INT8_MIN;
    for (int i = 0; i < size; i++){
        maxi=max(maxi,arr[i]);  // Makes the function even faster
        // if (arr[i]>max){
        //     max=arr[i];
        // }   
    }
    return maxi;
}



int main(){
    int minarr[8]={34,42,53,300,1,34,23,3};
    cout<<min(minarr,8)<<endl;
    cout<<mini(minarr,8)<<endl;
    cout<<maxi(minarr,8);
    
}
