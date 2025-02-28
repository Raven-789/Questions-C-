#include<iostream>
using namespace std;
int main(){
int num;
cout<<"Enter number: ";
cin>>num;
int num2;
cout<<"Enter another number: ";
cin>>num2;


    for (int j = num; j <= num2; j++)
    {
        int f=0;
        for (int i = 2; i <j; i++)
        {
            if (j%i==0)
            {
                f++;
                break;
            }
            // cout<<"hw";
        }
      if (f==0)
      {
        cout<<j<<endl;
        // f=0;
      }
    //   f=0;
    }

}