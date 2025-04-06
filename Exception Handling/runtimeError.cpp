#include<iostream>
#include<exception>
using namespace std;

int main(){
    try{
        throw runtime_error("Runtime error occured!!");
    }catch(exception &e){
        cout<<"Caught exception: "<<e.what()<<endl;
    }
}