//--------------------------------------------------Question 5------------------------------------------------------------------------------------------
//Question 5 get five 5 students' marks in five subjects (create a multidimesional array)

#include<iostream>
using namespace std;
int main(){
    int stuarr[2][2]={},num,tot=0,subj;
    for (int i = 0; i < 2; i++)
    {
        cout<<"Enter subject's marks for stuent "<<i+1<<endl;
        for (int j = 0; j < 2; j++)
        {
            cout<<"Enter marks for subject "<<j+1<<" :";
            cin>>stuarr[i][j];   
        }
    }

    for (int i = 0; i < 2; i++)
    {
        cout<<"For stuent "<<i+1;
        for (int j = 0; j < 2; j++)
        {
            tot=tot+stuarr[i][j];
            subj=j;
        }
        cout<<" the Average is "<< tot/(subj+1)<<endl;
    }
    // To see the array's elements of question 5-------------------------------
    // for (int i = 0; i < 2; i++)
    // {
    //     cout<<"For stuent "<<i+1<<endl;
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout<<"Marks for subject "<<j+1<<" :"<<stuarr[i][j]<<endl;
            
    //     }
    // }

}