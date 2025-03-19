#include<iostream>
#include<memory>
using namespace std;

void greet(){
    cout<<"Hello, World"<<endl;
}

int main(){
    int x=25;
    int *ptr=&x;

    cout<<"Value of x = "<<x<<endl;
    cout<<"Address of x ="<<&x<<endl;
    cout<<"Pointer stores = "<<ptr<<endl;
    cout<<"Value using pointer = "<<*ptr<<endl;

    int arr[]={10,20,30};
    int *ptr1=arr;

    cout<<"First element: "<<*ptr1<<endl;
    *ptr1++;
    cout<<"Second element: "<<*ptr1<<endl;
    *ptr1++;
    cout<<"Third element: "<<*ptr1<<endl;

    cout<<"For Loop Traversal: - "<<endl;
    ptr1=arr;//Resetting the pointer to base and you can't put it 0 as its address will change
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<"Element "<<i+1<<" of array: "<<*(ptr1+i)<<endl;
    }
    

    int y=44;
    int*ptry=&y;
    int **ptry2= &ptry;

    cout<<"Value of y: "<<y<<endl;
    cout<<"Using single pointer: "<<*ptry<<endl;
    cout<<"Using double pointer: "<<**ptry2<<endl;

    int *ptr2=new int(50); //Heap memory allocation using new
    cout<<"Value: "<<*ptr<<endl;
    delete ptr;//Freeing the allocated memory


    int* arr1=new int[3];

    arr1[0]=10;
    arr1[1]=20;
    arr1[2]=30;

    for (int i = 0; i < 3; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    delete[] arr1;

    void (*funcptr)()=greet;
    funcptr();

    unique_ptr<int>ptr3(new int(100));
    cout<<"Value: "<<*ptr3<<endl;
}
