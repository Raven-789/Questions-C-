#include<iostream>
using namespace std;
int main(){
    // you can only decide the starting point when printing a string ptr okay and it always prints whole array after that

    char str[]="Ashish";
    char *ptr=str;
    cout<<str[0]<<" "<<ptr[0]<<endl; // this how you can print single chars from string arrays

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";// it works something like firstly "abcde" is stored in a temp memory then that temp memeory is copied into the space which is allocated to ch[6]
    // bad practice
    // char *c="abcde";// don't do this bad practice it also works kind of similar like firstly the "abcde" is stored in a temp memory then its 1st element is pointed by the 
    //pointer then you don't know where you'll end up as no null character so you might end up tweaking something Read Only memory you know


    cout << arr << endl;//int arr gives the address of 1st element
    //attention here in the line below difference here
    cout<< ch<<endl;// char arr gives the elements of arr

    char *c=&ch[0];
    //difference here
    cout<<c<<endl;//in int arr it gives the 1st elemnt's address but here it gives the entire string
    //char arr prints whole string because it knows where to start from which is ch[0] in this case but
    //ends only when it encounters a null character '\0' 

    // if a string doesn't has null char then it stops only where null char is encountered which is at a 
    // radom place so hence the random characters
    char temp='z';
    char *p=&temp;
    cout<<p<<endl;//its random ok so that's why it can be repeated as you don't know what's sotred where

}