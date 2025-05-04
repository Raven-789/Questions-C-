#include<iostream>
using namespace std;


// needs improvement with getting the size of inner arrays from the pointers
void jaggeredArr(){
    int row,col;
    cout<<"Enter no. of rows: ";
    cin>>row;
    int arrr[row];
    
    int **arr=new int*[row];

    for(int i = 0 ; i < row ; i++){
        cout<<"Enter no. of columns for row "<< i<<" :" ;
        cin>>col;
        arrr[i]=col;
        arr[i]=new int [col];
    }
    // cout<< sizeof(*r)<<" "<<sizeof(arr[1])<<" "<<sizeof(arr[2]);
    // cout<<sizeof(arr[0]);
    // cout<<sizeof(arr[0]);

    // for(int i = 0 ; i < r ; i++){
        // for(int j = 0 ; j < c ; j++){
            
        // }
    // }

    for(int i = 0 ; i < row ; i++){
        cout<<arrr[i]<<endl;
        for(int j = 0 ; j < arrr[i] ;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<arrr[i];j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete[] arr;
}

int main(){
    int row,col;
    jaggeredArr();
}