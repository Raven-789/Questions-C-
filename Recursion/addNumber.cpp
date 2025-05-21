#include<iostream>
using namespace std;
int addno(int a){
    if (a== 1)
    {
        return 1;
    }
    // int b = a+(a-1);
    return a+ addno(a-1);
    // return b;
    
}
int main(){
    cout<<addno(5);
}