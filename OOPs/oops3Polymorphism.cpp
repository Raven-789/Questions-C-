#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Read the list of operators which can be overloaded in the link of reference

//Function Overloading (Compile Time / Static Polymorphism)

class A {
    public:
    //Function Overloading 
        void sayHello(){
            cout<<"Hello";
        }

        void sayHello(string n){
            cout<<"Helloo";
        }

        void sayHello(int n){
            cout<<"Hellooo";
        }
};

//Operator Overloading (Compile Time / Static Polymorphism)

class B {
    public :
        int a;
        int b;

        int add() {
            return a+b;
        }

        void operator+ (B &obj){
            int val1 = this -> a ;
            int val2 = obj.a;
            cout<< val1 - val2<<endl;
        }

        void operator() (){
            cout<<"Overload of brackets Successful!!!"<<endl;
        }
};


class Animal {
    public:
        void speak(){
            cout<<"speaking"<<endl;
        }
};

class Cat : public Animal {
    public:
        void speak(){
            cout<<"meowww"<<endl;
        }
};

class Dog : public Animal {
    public:
        void speak(){
            cout<< "barking..."<<endl;
        }
};

class Tiger : public Animal{

};

int main(){



    //Function Overriding

    // Dog d;
    // Cat c;
    // Tiger t;
    // Animal a;

    // d.speak();
    // c.speak();
    // a.speak();
    // t.speak();//if a class doesn't has that implementation it only calls parent class function


















    // //Operator Overloading
    // B obj1,obj2;
    // obj1.a = 7;
    // obj2.a = 4;

    // obj1 + obj2;
    // obj1();










    // A obj;
    // obj.sayHello("ff");

}

//Only changing return type isn't considered in overloading. You've to change the paramenters of the fucntions

//Runtime Polymorphism Method Overriding: same function name but different implementation in the child class yeah overriding is in inheritence 
// 
// functions must've same name
// should've same parameters
// Possible thorugh inheritence only (Runtime Polymorphism or Dynamic Polymorphism or Function Overriding)
// 
// 

