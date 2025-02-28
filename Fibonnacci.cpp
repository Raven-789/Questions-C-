#include <iostream>
using namespace std;
int main(){
    int n=0,i,f1,f2,f3;
    cout<<"Enter upper limit for fibonacchi series: ";
    cin>> n ;
    for (i=0; i <n; i++)
    {
        if (i<=1)
        {
            cout<<i<<endl;
            f1=1;
        }
        else if (i==2)
        {
            cout<<f1<<endl;
            f2=1;

        }
        else
        {
            f3=f1+f2;
            cout<<f3<<endl;
            f1=f2;
            f2=f3;
        }
    }
}
