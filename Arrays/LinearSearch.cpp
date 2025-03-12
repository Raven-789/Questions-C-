#include<iostream>
using namespace std;

bool search(int arr[],int size,int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==key)
        {
            return 1;
        }
        
    }
    return 0;

}

int main(){
    int arr[7]={33,45,77,43,66,2,35},key;
    cout<<"Enter element to find: ";
    cin>>key;
    bool found =search(arr,7,key);
    
    if (found)
    {
        cout<<"Element present!!";
    }else {
        cout<<"Element Absent!!";
    }
    
}