//Sorting arrays named file also has questjions like these in which arrays are passed into the functijons

//--------------------------------------------Passing Arrys to Functions-------------------------------------------------
#include<iostream>
using namespace std;

void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int nums[]={10,20,30,40,50};
    display(nums ,5);


}



//Question 6 create a fucntion to toake an array and gives the smallest element of the array
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
#include<iostream>
using namespace std;
int main(){
    int minarr[8]={34,42,53,322,1,34,23,3};
    cout<<min(minarr,8);
    
}
