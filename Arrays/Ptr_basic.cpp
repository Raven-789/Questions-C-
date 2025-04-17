#include <iostream>
#include<memory>

using namespace std;

void greet(){
    cout<<"Hello, World"<<endl;
}

int main() {
    int variable = 42; // A regular integer variable
    int* pointer = &variable; // A pointer that stores the address of 'variable'

    // Output the value of 'variable' and the address stored in 'pointer'
    cout << "Value of variable: " << variable << endl;
    cout << "Address of variable: " << &variable << endl;
    cout << "Pointer points to address: " << pointer << endl;
    cout << "Value at the address pointer points to: " << *pointer << endl;

    // Modifying the value using the pointer
    *pointer = 100; // Change the value of 'variable' through the pointer

    // Output the modified value of 'variable'
    cout << "Modified value of variable: " << variable << endl;

    int x=25;
    int *ptr=&x;
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

    //You have to include memeory header file to use unique ptr
    unique_ptr<int>ptr3(new int(100));//Smart ptr deletes the allocated memory automatically
    cout<<"Value: "<<*ptr3<<endl;
    
    //How initialize pointers LATER
    int i=5;
    int *q=0;
    q=&i;
    //Copying a pointer
    int *z=q;
    cout<<*q<<" - "<<*z<<endl;
    cout<<q<<" - "<<z<<endl;

    //Bad practice
    int *k; //now the pointer is pointing to a garbage value

    //important concept
    i=3;
    int *t=&i;
    cout<< (*t)++<<endl;
    // *t=*t+1;
    cout<<*t<<endl;
    cout<<"before t "<<t<<endl;
    t=t+1;//this doesn't makes the address +1 like if the address is 105 it doesn't get 106 it first leaves the exact space taken by that datatype as in int its 4 bytes so 105 becomes 109 ok
    cout<<"after t "<<t<<endl;
    return 0;
}