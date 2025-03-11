// #include <iostream>
// using namespace std;

// int main() {
//     // Declaring and initializing an array
//     int arr[5] = {10, 20, 30, 40, 50};
    
//     // Accessing elements of the array
//     cout << "Elements of the array: " << endl;
//     for (int i = 0; i < 5; i++) {
//         cout << "arr[" << i << "] = " << arr[i] << endl;
//     }

//     // Modifying elements in the array
//     arr[3] = 100;  // Changing the value of the third element

//     // Accessing the modified array
//     cout << "\nAfter modifying the third element: " << endl;
//     for (int i = 0; i < 5; i++) {
//         cout << "arr[" << i << "] = " << arr[i] << endl;
//     }

//     return 0;
// }

// ⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

#include<iostream>
using namespace std;
int main(){
     //(IT ONLY WORKS FOR ZERO 0) How to initialize arr with only 1 val 
    // int arr[100]={0},i=0;
    int arr[100];
    fill_n(arr,100,24); //use this fill_n command to or for loop to do it for any val and see its arguements
    int i=0;
    while(i!=100){
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl<<endl<<endl;
    int arr1[100]={1};  // if you try to do it like before for any other no. its just gonna initialize 1st
                        //  index with that no. and all others with 0
    for (int i = 0; i < 100; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl<<endl<<endl;

    int arr2[100]={1,2,3,4}; //this also only inititalizes only first 4 indexes observe you can get it easily
                            //and all other vals are initialized by 0
    for (int i = 0; i < 100; i++)
    {
        cout<<arr2[i]<<" ";
    }
}