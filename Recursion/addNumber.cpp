#include<iostream>
using namespace std;
int addno(int a){
    if (a==1)
    {
        return 1;
    }
    return a+addno(a-1);
    
}
int main(){
    cout<<addno(5);
}