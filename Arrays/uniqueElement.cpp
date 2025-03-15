//This code doesn't works if there are Multiple unique elements in the array 
//and questions is also that there is only 1 unique element in the whole array

// #include<iostream>
// using namespace std;

// int unique(int arr[],int size){
//     bool chk=1;
//     for (int i = 0; i <= size; i++)
//     {
//         for (int j = i+1; j <= size; j++)
//         {
//             if (arr[i]==arr[j])
//             {
//                 chk=0;
//             }
            
//         }
        
//         if (chk)
//         {
//             return arr[i];
//         }
//         chk=1;
        
//     }   
// }

// //Faster one
// int findUnique(int arr[],int size){
//     int ans=0;
//     for (int i = 0; i < size; i++)
//     {
//         ans=ans^arr[i] ; //XOR OPERATOR used as when we XOR same elements it gives 0 so same elements get canclled
//     }
//     return ans;
// }

// int main(){
//     int arr[5]={1,3,4,1,3};
//     // cout<<unique(arr,4);
//     cout<<findUnique(arr,5);
// }

//⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

// Another question
//if the OCCURRENCES of the elements are unique give true

