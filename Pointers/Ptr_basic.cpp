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
    



     int arrmy[10] = {23, 122, 41, 67};
   
    cout <<" address of first memory block is " << arr << endl;
    cout << arrmy[0] << endl;
    cout <<" address of first memory block is " << &arr[0] << endl;

    cout << "4th " << *arrmy << endl;
    cout << "5th " << *arrmy + 1 << endl;
    cout << "6th " << *(arrmy + 1) << endl;
    cout << "7th " << *(arrmy) + 1 << endl;
    cout << "8th " << arrmy[2] << endl;
    cout << "9th " << *(arrmy+2) << endl;
    

     i = 3;
    cout << i[arrmy] << endl;
    //formulas :- for above line so technically both of them work okay
    // arr[i] =*(arr+i)
    // i[arr]=*(i+arr) // as arr is what give you address if you cout<<arr; you know so *(arr) gives the value inside that address (1st element in default after that you can add no. to it to access other elements of arr)

    int temp_my[10] = {1,2,3};
   cout << sizeof(temp_my) << endl;//gives the space of whole array
   cout << " 1st " <<  sizeof(*temp_my) << endl;//printing gives temp gives address of 1st element and then * gives the element in that address which is int then sizeof gives space of that int
   cout << " 2nd " <<  sizeof(&temp_my) << endl;//& gives the address' size in which the 1st element is stored

   int *ptr4 = &temp_my[0];
   cout << sizeof(ptr4) << endl ;//gives the size of ptr which stores the address
   cout << sizeof(*ptr4) << endl ;//gives the size of address which is stored in the int pointer
   cout << sizeof(&ptr4) << endl ;//gives the size of address in which the pointer is stored



   int a[20] = {1,2,3,5};
   cout << " ->" << &a[0] << endl;
  cout << &a << endl;//gives the address of 1st element
   cout << a << endl;//also //gives the address of 1st element

   int *p = &a[0];
   cout << p << endl;//gives the addres of pointer
   cout << *p << endl;//gives the element stored in the pointer
   cout << "-> " << &p << endl;

   //line below give an error
   int arr[10];
//    arr=arr+1; //ERROR

    // but if you'll try to do above line in ptr it'll work as that's pointer arithmetic so it'll 
    //just move to the address of of next element when you +1 the pointer which'll be +4 in int arr's case
    //cause' each element in int arr takes 4 bytes you know
}