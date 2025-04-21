#include <iostream>
using namespace std;
int main(){
    int row,col;
    cin>>row;
    cin>>col;
    
    //creating the 2D arr

    int **arr=new int*[row];
    for(int i=0;i<col;i++){
        arr[i]=new int [col];
    }


    //taking input
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }cout<<endl;

    //taking Output
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    //deallocation of memeory manually
    for(int i=0;i<row;i++){
        delete [] arr[i]; //firstly deleting the 1D arrays which being pointed to by an array of pointers
    }
    delete[] arr;
}