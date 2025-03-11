#include<iostream>
using namespace std;

//Inline Function
inline int square(int y){
    return y*y;
}

//Call by value
void modify (int x){
    x=x+10; //Changes only the local fopy
    cout<<"Inside Function: "<<x<<endl;
}

//Pass by Reference
void modify1(int &x){
    x=x+10;
    cout<<"Inside Function: "<<x<<endl;
}

//Pass by Pointer
void modify2(int *x){
    *x=*x+10;
    cout<<"Inside Function: "<<*x<<endl;
}

//Function Overloading
void display(int a){
    cout<<"Integer: "<<a<<endl;
}

void display(double a){
    cout<<"Double: "<<a<<endl;
}

void display(int a,double b){
    cout<<"Integer & Double: "<<a<<endl;
}
// ---------------------------------------------------------


//Default Arguments
void greet1(string name ="Guest"){
    cout<<"Hello, "<<name<<"!!"<<endl;
}

int main(){
        // cout<<"Square of 5: "<<square(5);
    // int num=20;
    // modify(num);
    // cout<<"Outside Function: "<<num<<endl;
    // int num=20;
    // modify1(num);
    // cout<<"Outside Function: "<<num<<endl;
    // int num=20;
    // modify2(&num);
    // cout<<"Outside Function: "<<num<<endl;
    // display(5);
    // display(3.14);
    // display(10,5.5);
    greet1();
    greet1("Alice");
}


//⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻


#include<iostream>
#include<math.h>
using namespace std;

void greet();
void addNumbers(int a , int b){ //Fnction with not return type & with Parameters
    cout<<"Sum: "<<a+b<<endl;
}

int getnumber(){ //Function without parameters & with return type
    return 42;
}

int multiply(int a,int b){ // Function with Parameters & with Return Type
    return a*b;
}

int main(){
    // cout<<"Square root of 25: "<<sqrt(25)<<endl;
    // cout<<"Power: "<<pow(2,3)<<endl;
    // cout<<"Absolute Value: "<<abs(-8)<<endl;
    greet2();
    addNumbers(10,20);
    cout<<"Returned Value: "<<getnumber()<<endl;
    int result=multiply(5,6);
    cout<<"Multiplication Result: "<<result<<endl;
    return 0;
}

void greet2(){
    cout<<"Hello, welcome to C++ functions!!"<<endl;
}