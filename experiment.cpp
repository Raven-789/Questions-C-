#include <iostream>
#include<bits/stdc++.h> //Use this one for all structures
#include<cstring>
using namespace std;

class Hero {
private:
    char* name;
    int power;

public:
    // Default constructor
    Hero() : name(nullptr), power(0) {}

    // Parameterized constructor
    Hero(const char* n, int p) : power(p) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy constructor
    Hero(const Hero& other) : power(other.power) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }

    // Destructor
    ~Hero() {
        delete[] name;
    }

    void display() const {
        cout << "Name: " << (name ? name : "Unknown") << ", Power: " << power << endl;
    }
};


int main(){

    cout<<9/2;

}