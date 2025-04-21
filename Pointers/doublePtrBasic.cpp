#include<iostream>
using namespace std;

// void update(int *p) {
void update(int **p2) {

    // p2 = p2 + 1; //doesn't work at all as its pass by val you know
    
    *p2=*p2+1;//? it changes the address to other one does works gives a garbage val tho if its *p the val as the *p is UPDATED 

    // **p2=**p2+1;// this means go in 2 levels inside p2 and then increment that val which is 5 in this case
 
 }

int main(){
    int i = 5;
    int arr[]={1,2,3,4};
    // cout<<*(arr++);//ERROR as you can't increment the things in Symbol table
//  Symbol Table is a table maintained by compiler to note which variable (made by the user) is pointing to which address
    int *ptr;
    cout<<"Size of integer pointer : "<<sizeof(ptr)<<endl;// its takes 4 bytes
    // int *y=5; //this is ERROR as you can store only address in pointers as *y only gives the element in the respective address
    // int *y=0;// but zero works as its a null pointer
    int* p = &i;
    int** p2 = &p;

    char ch='a';
    char *ptrch=&ch;
    // ch++;// we got b rather than a garbage val as we incremented ch and not *ptrch as its ch's address which would then give a grabage val or the null character 
    cout<<*ptrch<<endl;
//     cout<<"To get the address of i:"<<endl;
//     cout<<&i<<endl;
//     cout<<p<<endl;//this gives address stored of the i
//     cout<<*p2<<endl;//this gives the stored of the i too as its pointing to content of *p which is address of i in this case

// //  to get the content of i
//     cout<<"content of i:"<<endl;
//     cout<<**p2<<endl;//this gives 5 as its pointing to i's address which stores 5
//     cout<<i<<endl;//also gives 5
//     cout<<*p<<endl;//also gives 5 as * gives the value in the pointed address

// //  to get the address of  *p first pointer
//     cout<<"Adress of p first pointer:"<<endl;
//     cout<<&p<<endl;// just this will give you address stored in it "cout<<p<<endl;" which is of i at lowest level
//     cout<<p2<<endl;// "cout<<*p2<<endl;" will give you address stored in it which is also of i at the lowest level
    
//  update function
    // cout<<i<<endl;
    cout <<" Before i " << i << endl;
    cout <<" Before *p " << *p << endl;
    cout<<" Before p "<<p<<endl;
    cout<<" before p2 "<< p2<<endl;
    // update(p);
    update(p2);
    cout <<" After i " << i<< endl;
    cout <<" After *p " << *p<< endl;
    cout<<" After p "<<p<<endl;
    cout<<" After p2 "<< p2<<endl;
    
    
}