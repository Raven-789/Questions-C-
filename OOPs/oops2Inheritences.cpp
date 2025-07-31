#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//1:05:00 about industry level OOPs as they're different in vid of lecture 43
//read about inehritence HW


//student class shows simple class which also as Encapsulation okay which we did before

class student{
    private:
        int age;
        string name;
        int height;

    public:
        int getAge(){
            return age;
        }
};

//  Inheritence-----------------------------------------------------------------------------------------

class human{
    private:
        int age;

    protected:
        int height;

    // 


    public:
        int weight;
    
    public:    
        int getAge(){
            return age;
        }

        void setWeight(int weight){
            this -> weight = weight;
        }
};


//  Single Inheritence-------------------------
class male : public human{
    public:
        string color;

        void sleep(){
            cout<<"Sleeper"<<endl;
        }

        int getHeight(){
            return this -> height;
        }
};



//Mltilevel Inheritence--------------------------------------------
class animal{
    public:
        int age;
        int weight;

    public:
        void speak(){
            cout<<"Speaking..."<<endl;
        }
        void getAge(){
            cout<<age;
        }
};

class dog : public animal{
    public:
        void barking(){
            cout<<"Barking..."<<endl;
        }
};

class germanShephard : public dog{

};


//  Multiple Inheritence
class manBeast : public dog,public human{   //Give access specifer for both classes 

};


//  Hiearchial Inheritence---------------------------------------------------------------------------------------
//  when one class is parent to 2 or more child classes
// its like a tree of hiearchy and the child also might be parent to multiple child classes just like a tree


class lion : public animal{
    public:
        void roar(){
            cout<<"Roaring..."<<endl;
        }
};

class giraffe : public animal{
    public:
        void height(){
            cout<<"80 ft"<<endl;
        }
};


//  Hybrid Inheritence : when you use more than one type of inheritence-----------------------------------------
//as we cann see beast is has used multiple inheritence and myltilevel inheritence and hiearchial inheritence
class beast : public  dog,public human{ //Provide access specifier for both classes

};


int main(){


    // Scope Resolution Operator

    beast b2;
    cout<<"Human class weight: "<<b2.human::weight<<endl;

    cout<<"Animal class getAge function: ";
    b2.animal::getAge();

    cout<<endl<<"Human class getAge function: "<< b2.human :: getAge()<<endl;











    // //Hybrid Inheritence
    // beast be1;
    // be1.speak();
    // cout<<be1.getAge()<<endl;
    // be1.setWeight(50);
    // //use scope resolution operator like above
    // // cout<<be1.weight<<endl;//can't use weight as its also in animal and in human so the call for it becomes ambigious 

    // // like this : - 
    // cout<<be1.human :: weight<<endl;










    //Hiearchial Inheritence
    // giraffe g1;

    // g1.speak();
    // g1.height();


    // lion l1;

    // l1.roar();
    // l1.speak();














    // //Multiple Inheritence
    // manBeast b1;
    // b1.barking();
    // b1.speak();
    // use scope resolution operator 
    // // b1.weight = 90;//can't use weight as its also in animal class so its call becomes ambigious
    

    // //like this: - 
    // b1.animal :: weight = 50;
    // cout<<b1.animal :: weight<<endl;















    // //Multilevel Inheritence

    // germanShephard g1;
    // g1.speak();
















    // male obj1;

    // // cout<<obj1.age<<endl;    //age can't be accessed as its a pvt data member
    // cout<<obj1.weight <<endl;
    // cout<<obj1.getHeight()<<endl;


    // // obj1.age = 11;   //age can't be accessed as its a pvt data member
    // obj1.weight = 33;

    // // obj1.height()  = 5;  // this can't be done as height is protected

    // // cout<<obj1.age<<endl;    //age can't be accessed as its a pvt data member
    // cout<<obj1.weight <<endl;
    // cout<<obj1.getHeight()<<endl;
    // obj1.sleep();
    // obj1.setWeight(55);

    // cout<<obj1.weight <<endl;

















    // student first;
    // cout<<"OK";
}


//Encapsulation 
//  Data Hiding so security increases 
//  We can made program "read only"
//  Code reusability
//  Helps in Unit - Testing




// Access specifers : -
// Private : can only be accessed inside class. If inheritence mode is pvt. then all the public, protected & pvt. members become pvt. in child

// Protected : protected is similar to pvt can only access it inside class.But it can also be accessed by child class or derived class that's
//  also only inside child class. If inheritence mode protected then all pvt, public & protected members become protected in child class.


// Public: can be accessed anywhere. Inheritence mode public ONLY public elements of base class are inherited in child class as public members

// Base Class Access  |         Public              Protected               Private
// Specifier          |
//                    |
// Public             |         Public              Protected               Private
// Protected          |         Protected           Protected               Private
// Private            |         Not Accessible      Not Accessible          Not Accessible

