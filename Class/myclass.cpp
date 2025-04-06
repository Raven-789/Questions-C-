#include<iostream>
using namespace std;

class Animal {
    public:
        string name;
        string sound;

      
          // Parameterized Constructor
        Animal(string name, string sound) : name(name), sound(sound){}

           void make_sound()
        {
                cout<<name<<sound;
            }
        };
        

class dog : public Animal
{
public:
    dog():Animal("unknown","bark") {}
    
};



int main(){

    dog d;
    d.name="tommy";
    d.make_sound();
    cout<<endl<<d.name;

}