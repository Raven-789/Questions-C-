#include<iostream>
#include<bits/stdc++.h>
// #include "Hero.cpp" //includes other class from different file
using namespace std;

// Greedy alignment and padding in memory of class in C++ Read about them in vid 1st HW DONE AT THE END OF CODE OUTSIDE INT MAIN

class hero{

    // properties
    private://can only be accessed inside of class like by function printName
        string name;
        int power;
        
    public://can be accessed inside the class
        int health;
        string level;
        char *alias;
        static int timeToComplete;
        const char status [8] = "Fighter";
        const string clan = "";


    hero(){
        cout<<"Constructor Called"<<endl;
        alias = new char [100];
    }

    // Copy constructor
    hero(hero &temp){


        //Deep COPY HERE
        char *ch = new char [strlen(temp.alias)+1] ;
        strcpy(ch,temp.alias);
        this -> alias = ch;//we'll use ch here as we want the inital copy of Victor's class not everytime we update Victor's class or else 
                            //there won't be any difference b/w victor and Asuka's class in the end okay


        this -> name = temp.name;
        this -> level = temp.level;
        this -> health = temp.health;

        
        cout << "Copy constructor called"<<endl;
    }

    hero(string name){
        this -> name = name;
        cout<<"Address of \"this\" function of "<< name <<"'s object: " <<  &this->name << endl;
        cout<<"Parameterized Constructor"<<endl;
    }

    // hero(string name, string level){
    //     this -> name = name;
    //     this -> level = level;
    //     cout<<"2 Parameters Constructor"<<endl;
    // }



    //Initilazition list:
    //  to test it comment 2 Parameters Constructor first  okay

    hero(string n, string c) : clan(c), name(n) {
        cout<<"[ Name: "<< getName();
        cout<< ", Clan: "<< c<<" ]"<<endl;
    }

    


    string getStatus() const{
        // return status = "Dragon"; // even const functions can't modify const data members
        return status;
    }

    string getName(){
        return name;
    }

    int getPower(){
        return power;
    }

    int getHealth(){
        return health;
    }

    string getLevel(){
        return level;
    }

    string getAlias(){
        return alias;
    }

    void setName(string n){
        name = n;
        // cout<<n;
    }

    void setPower(int p){
        power = p;
    }

    void setHealth(int health){
        this -> health = health;
    }

    void setLevel(string l){
        level = l;
    }

    void setAlias(char alias[] ){ //put the name before the square brackets you FORGOT IT OK
        strcpy( this -> alias, alias);//you've to copy alias into this->alias as alias is user input here and other one is empty
    }

    //SetStatus won't work as its trying to modify the const it got to class' const data member

    // void const status(const string status){
    //     this -> status = status;      //Modification is being done here
    // }

    ~hero(){
        cout<<"Destructor called"<<endl;
    }

    static int random (){
        
        // static function can only access static members


        // return level;
        // return this->health;

        return timeToComplete;
    }

};

int hero :: timeToComplete = 90;


int main (){


    // Initization List
    // used in constructors
    // used to initilaze const (compulsory) , ref data members and members which have data type class which don't have default contructors
    // Base class data members initiliztion (Inheritence)
    // Gives a way to put value in const data members     

    hero Feng ("Feng","Wei");
    //wei is clan which is const data member which we put initial val in using initilazition list



















    // //Const keyword
    // // can't modify data member which is const 
    // // member function declared const can only display its arguement not modify it
    // // const onj can't be modified after construction (constructors...)
    // const hero Azazel;
    // // Azazel.setStatus  = "Dragon"; //can't modify the const as said before
    // Azazel.getStatus()[0]='L';
    // cout<<Azazel.getStatus()<<endl; //as we can see we can't modify const char array like this too















    // Static functions 
    // don't have any need to create objects
    // don't have this keyword as this keyword is for accessing current objects and it doesn't have objects
    // static functions can only access static members
    // cout<<hero::timeToComplete<<endl;




//     // Static Data Members
// //      to access it no need to make objects
// //      belongs to class      
// //      need to be initialized which is done outside class
   
//     cout<<hero::timeToComplete<<endl;


//     hero Katrina;
//     cout<<Katrina.hero::timeToComplete<< endl;

//     hero Lilli;
//     cout<<Lilli.hero::timeToComplete<<endl;

//     Lilli.hero::timeToComplete = 70;
//     cout<<Lilli.hero::timeToComplete<< endl;
//     cout<<Katrina.hero::timeToComplete<< endl;

// //  static memeber can be accessed by any object but you shouldn't do it with objects as its independent of
// //  objects itself and belongs to class only



// //  objects can also be used to update but then again don't use them with objects you can also change static
// //  data members only too


//     hero::timeToComplete=60;
//     cout<<hero::timeToComplete<<endl;
















//     //Destructor
// //    object deallocation
// //    No return type
// //    No input parameter
// //    Automatic invocation for STATIC OBJECTS ONLY for DYNAMIC OBJECTS YOU'VE TO CALL IT MANUALLY
// //    it has a TILDE sign(~)


//     //Static
//     hero Bryan;



//     //Dynamic
//     hero *Lee = new hero;
//     //for dynamic objects you've to call destructor manually like : -
//     delete Lee; //if you don't do it you'll see in terminal that destructor is only called once  or if the constructors have used new in their initilization















    // // Copy using Assignment Operator

    // hero Reina;
    // Reina.setName("Reina");
    // Reina.setHealth(100);
    // Reina.setPower(100);

    // hero Jun;
    // Jun.setName("Jun");
    // Jun.setHealth(101);
    // Jun.setPower(99);

    // cout<<"Jun's stats: "<<"[ "<<Jun.getName()<<" , " <<Jun.getHealth()<<" ]"<<endl;
    // cout<<"Reina's stats: "<<"[ "<<Reina.getName()<<" , " <<Reina.getHealth()<<" ]"<<endl;

    // //Using assignment Operator to copy objects which were already created

    // Reina = Jun;
    // cout<<"Jun's stats: "<<"[ "<<Jun.getName()<<" , " <<Jun.getHealth()<<" ]"<<endl;
    // cout<<"Reina's stats: "<<"[ "<<Reina.getName()<<" , " <<Reina.getHealth()<<" ]"<<endl;














    // // Copy Constructor Shallow and Deep Copy (around at line 30 at Copy constructor see it if you want to)

    // hero Victor;
    // Victor.setName("Victor");
    // Victor.setHealth(150);
    // Victor.setLevel("A");
    // char al [7]  = "Killer"; //the space is +1 the length cause' last has to reserved for /0 character
    // Victor.setAlias(al);


    // cout<<"Victor's stats: "<<"[ "<<Victor.getName()<<" , " <<Victor.getHealth()<<" , " <<Victor.getLevel()<<" , " <<Victor.getAlias()<<" ]"<<endl;

    // hero Asuka (Victor);
    // //Asuka = Victor;

    // cout<<"Asuka's stats: "<<"[ "<<Asuka.getName()<<" , " <<Asuka.getHealth()<<" , " <<Asuka.getLevel()<<" , " <<Asuka.getAlias()<<" ]"<<endl;


    // Victor.alias[0]='F';
    // cout<<"Victor's stats: "<<"[ "<<Victor.getName()<<" , " <<Victor.getHealth()<<" , " <<Victor.getLevel()<<" , " <<Victor.getAlias()<<" ]"<<endl;


    // //Shallow copy: as we only chaged the Victor's name's first character but it also got sopy into Asuka's stats you can try by just inbuilt copy
    // //  constructor by just commenting your own copy constructor
    // cout<<"Asuka's stats: "<<"[ "<<Asuka.getName()<<" , " <<Asuka.getHealth()<<" , " <<Asuka.getLevel()<<" , " <<Asuka.getAlias()<<" ]"<<endl;


    // // Copy Constructor

    // hero Angel("Angel","S");

    // hero Hawoarang(Angel); //Inbuilt copy constructor called which is there only until you make your own user defined copy constructor

    // hero Ling(Hawoarang);
    // cout<<Ling.getName()<<" "<<Ling.getLevel()<<endl;



















//     //if you remove the hero() constructor then the hero devil won't work as we already've other constructors
//     //and soo the inbuilt constructor won't be there ok

//     //Inbuilt constructor :-
// //    object creation
// //    No return type
// //    No input parameter
// //    Automatic invocation
// //         

//     cout<<"Static"<<endl;

//     hero Devil;

//     hero King("King");
//     cout<<"King's object address: " << &King<<endl;

//     hero Eddy("Eddy","SS");



//     cout<<"Dynamic"<<endl;

//     hero *Mokujin = new hero();

//     hero *Raven = new hero("Raven");
//     cout<<"Raven's object address: "<< Raven<<endl;// you shouldn't use *Raven as it'll give another address then
    
//     hero *Jack8 = new hero("Jack8", "SS") ;

















    // //Static Allocation

    // hero Yousimitsu;

    // Yousimitsu.setName("Yousimitsu");
    // Yousimitsu.setLevel("S");

    // cout<<"Name: "<<Yousimitsu.getName()<<endl;
    // cout<<"Level: "<<Yousimitsu.getLevel()<<endl;



    // //Dynamic Allocation

    // hero *Paul = new hero;

    // (*Paul).setName("Paul");
    // (*Paul).setLevel("S");

    // cout<<"Name"<< (*Paul).getName()<<endl;
    // cout<<(*Paul).getLevel()<<endl;

    // Paul->setHealth(7777);
    // Paul->setPower(7777);
    
    // cout<< "Health " <<Paul->getHealth()<<endl;
    // cout<< "Power " <<Paul->getPower()<<endl;
    














    // hero Jin, Gon;
    // Jin.health=77;
    // Jin.level="S";
    // //when the class is empty completely the size is 1 as 1 byte is allocated to keep track of class and to identify it


    // //this is the getter and setter way of class
    // Gon.setName("Gon");
    // Gon.setHealth(1000);
    // Gon.setLevel("SSSS");
    // Gon.setPower(99999);
    // cout<<"Name: "<<Gon.getName()<<" Health: "<<Gon.getHealth()<<" Level: "<<Gon.getLevel()<<" Power: "<<Gon.getPower();

    // cout<< "Size of class: "<<sizeof(Jin)<<endl;
    // cout<<"Health of Hero: "<<Jin.health<<endl;
    // cout<<"Level of Hero: "<<Jin.level<<endl;

}


// Greedy alignment and padding in memory of class in C++ Read about them in vid 1st HW its related to constructors memory allocationD

//Greedy Alignment: Aims to reduce the memory padding by declaring the data members in a order
// where largest data member is declared first this reduces padding

//Padding : when data members aren't aligned acc. to memory alignment compiler inserts empty
//bytes b/w them to ensure proper alignment. This wastes memory 

// Mordern CPUs: they're req. data to be aligned in specific memeory addresses like -> 4 byte 
// int needs to be at an address which is a multiple of 4 this improves performance and prevents 
// undefined behaviour


