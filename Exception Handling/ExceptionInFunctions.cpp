#include<iostream>
using namespace std;

// void divide(int a ,int b){
//     if (b==0)
//     {
//         throw "Division by zero!";
        
//     }
//     cout<<"Result: "<<a/b<<endl;
// }

// int main(){
//     try
//     {
//         divide(10,2);
//         divide(5,0);//Throw an exception
//     }
//     catch(const char *msg)
//     {
//         cout<<"Exception: "<<msg<<endl;
//     }
    
// }

//----------------------------------------------------------------------------------------------------------------------------------------
void check (int age){
    if (age<0)
    {
        throw "Negative age not allowed!!";
    }
    if (age<18)
    {
        throw age;
    }
    cout<<"You are eligible!"<<endl;
}

int main (){
    try{
        check(-1);
    }
    catch(const char *msg){
        cout<<"Error: "<<msg<<endl;
    }
    catch(int age){
        cout<<"You're too young. "<<age<<endl;
    }
}