#include<iostream>
using namespace std;

void test(int x){
    try
    {
        if (x==0)
        {
            throw x; //Throwing an integer
        }
        else if (x==1)
        {
            throw "String Exception"; //Throwing a string
        }else{
            throw 4.5; //Throwing a double
        }  
    }
    catch(int e)
    {
        cout<<"Caught an Interger: "<<e<<endl;
    }
    catch(const char *e){
        cout<<"Caught a string : "<<e<<endl;
    }
    catch(...){
        cout<<"Caught an unknown exception!!!"<<endl;
    }
    
}
int main(){
    test(0);
    test(1);
    test(2);
}