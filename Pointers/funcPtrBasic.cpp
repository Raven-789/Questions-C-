#include<iostream>
using namespace std;

void print(int *p) {

    cout << *p << endl; 

}

void update(int *p) {

    //this tells us that you can't update the address of the pointer no matter what ok
   // p = p + 1;
   //cout << "inside "<< p <<endl;
   *p = *p + 1;

}

int getSum(int *arr, int n) {// that *arr is the default which is not shown when we pass array in a function

    cout << endl << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
/*
    int value = 5;
    int *p = &value;

    //print(p);
    cout <<" Before " << *p << endl;
    update(p);
    cout <<" After " << *p << endl;
    */

    int arr[6] = {1,2,3,4,5,8};

    //by adding a no. to the arr (as its ptr of arr passing by default) we can send a part of the
    //arr too to the function
    cout << "Sum is " << getSum(arr+3 ,3) << endl ;  

    return 0;
}