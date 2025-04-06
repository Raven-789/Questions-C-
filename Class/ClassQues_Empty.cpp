#include<iostream>
#include<memory>
#include<math.h>
using namespace std;

class car
{

public:
    string brand;
    int speed;

    void display(){
        cout<<"Brand: "<<brand<<", Speed: "<<speed<<"km/h"<<endl;
    }
};

class BankAcc{
    private:
        double balance;
    public:
        void setBalance(double amt){
            if (amt>0)
            {
                balance=amt;
            }else{
                cout<<"Invalid Amount!!!"<<endl;
            }
        }
        double getBalance(){
            return balance;
        }
};

//Ques 1
class rectangle
{
private:
    int width;
    int height;
public:
    float calculate_area(int width,int height){
        return width*height;
    }
};

class circle
{
private:
    int radius;
public:
    float calculate_area(int radius){
        return 3.14*pow(radius,2);//I was thinking M_Pi but use 3.14 for simplicity
    }
    float calculate_circumference (int radius){
        return 2*3.14*radius;
    }
};

class bankAccount
{
private://Private info can only be accessed by class functions okay
    int acc_number;
    int balance=0;
public:
    
    void deposit(int acc_number,int deposit_amt){
        
        balance=balance+deposit_amt;
        cout<<"Amount Deposited!!"<<endl;
    }
    void withdraw(int acc_number,int withdrawal_amt){
        if (balance<withdrawal_amt)
        {
            cout<<"Insufficient Balance!!!!!!"<<endl;
        }else{
            balance=balance-withdrawal_amt;
            cout<<"Collect the cash!!!"<<endl;
        }
    }
    void show_Balance(){
        cout<<"Current Balance: "<<balance<<endl;
    }
};

class student
{
private:
    string name;
    int age;
    int marks[3];
public:
    int calc_avg_grade(int marks[]){
        int sum=0;
        
        for (int i = 0; i < sizeof(marks)-1; i++)
        {
            sum=sum+marks[i];
        }
        cout<<"Average of Student is: " <<sum/3<<endl;
    }

};

//Ques 4
class animallss
{
public:
    string name,sound;
    string makeSound(){
        cout<<name<<" does "<<sound;
    }
};

class doogg:public animallss
{
public:
    string name="Dogg";
    string sound="Barkkk";


};
class catt:public animallss
{

public:
    string name="catt";
    string sound="Mewwing";
};

class cow:animallss
{

public:
    string name="Cow";
    string sound="Mooowww";
};






//-------------------------------------------------Inheritence----------------------------------------------------------------
//Single Inheritance
class Animal
{
    public:
        void eating(){
            cout<<"Eating..."<<endl;
        }
};

class Dog : public Animal{
    public:
        void bark (){
            cout<<"Barking..."<<endl;
        }
};


//Multiple Inheritance Child has 2 parents-----------------------------------------------------------------------------------------------
class Vehicle{
    public:
        void showVehicle(){
            cout<<"This is a Vehicle"<<endl;
        }
};

//Second Base Class
class Engine
{

public:
    void showEngine(){
        cout<<"This an engine."<<endl;
    }
};

//Derived Class
class Car:public Vehicle,public Engine{
    public:
        void showCar(){

        }
};

//Multilevel Inheritance-----------------------------------------------------------------------------------------
class Animalss
{

    public:
        void eattt(){
            cout<<"Eating..."<<endl;
        }
};

class Mammal:public Animalss
{

public:
    void Walkkk(){
        cout<<"Walking"<<endl;
    }
};

class Dogg:public Mammal
{
public:
    void barkkk(){
        cout<<"Barking..."<<endl;
    }
};

//Hiearchiacal Inheritance 1 base class has multiple derieved classes
class animal
{

public:
    void eatt(){
        cout<<"Eating"<<endl;
    }
};

class DOGG:public animal
{

public:
    void barkk(){
        cout<<"Barking"<<endl;
    }
};

class cat :public animal
{

public:
    void meow(){
        cout<<"Mewing..."<<endl;
    }
};

//Polymorphism----------------------------------------------------------------------------------
class Math
{
public:
    int add(int a ,int b){
        return a+b;
    }
    double add(double a,double b){
        return a+b;
    }
};





int main(){
    car car1;
    car1.brand="Toyota";
    car1.speed=123;
    car1.display();

    BankAcc acc;
    acc.setBalance(7777);
    cout<<"Balance: "<<acc.getBalance();
    bankAccount acc1;
    acc1.deposit(123,5000);
    acc1.withdraw(123,5000);
    acc1.show_Balance();
    student s1;
    int marks[]={22,33,44};
    s1.calc_avg_grade(marks);

    catt ca;
    cow co;
    doogg dg;
    dg.name;
    dg.makeSound();

//  Inheritance
    Car c;
    c.showVehicle();
    c.showEngine();
    c.showCar();

    Dogg d;
    d.eattt();
    d.Walkkk();
    d.barkkk();

    //Polymorphism
    Math obj;
    cout<<obj.add(5,3)<<endl;
    cout<<obj.add(2.5,3.5)<<endl;

    
    // 15:33
}