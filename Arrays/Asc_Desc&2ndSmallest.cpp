#include<iostream>
using namespace std;

int main(){
    int n,j;
    string ch;
    cout<<"Enter size of array: ";
    cin>>n;
    

    int* arr = new int[n],i,nm;
    // int* arr[n],i;
    
// to input elements in array
    for ( i = 0; i <= n-1; i++)
    {
        cout<<"Enter element "<<i+1<<" of the array: ";
        cin>>arr[i];  
    }
    cout<<endl;
// to dispay the inputed array
    // for(i=0;i<=n-1;i++)
    // {
    //     cout<<i+1<<" element of the array: ";
    //     cout<<arr[i]<<endl;
    // }

// for asc or desc choice

    cout<<"Which order do you want (asc/desc): ";
    cin>>ch;

// first is desc condition
//                      [5,10,7,9]
    if (ch=="desc" or ch=="Desc") 
    {
        for ( i = 0; i < n-1; i++)
        {
            for ( j = 0+(i+1); j < n; j++)
            {
                if (arr[i]>arr[j])
                {}
                else if (arr[i]<arr[j])
                {
                    nm=arr[i];
                    arr[i]=arr[j];
                    arr[j]=nm;
                }
            }
        }
    }
    else if (ch=="asc" or ch=="Asc")
    {
        for ( i = 0; i < n-1; i++)
        {
            for ( j = 0+(i+1); j < n; j++)
            {
                if (arr[i]<arr[j])
                {}
                else if (arr[i]>arr[j])
                {
                    nm=arr[i];
                    arr[i]=arr[j];
                    arr[j]=nm;
                }
            }
        }
        }    

if (ch=="Asc" or ch=="asc")
{
    cout<<"The Ascending Order is : "<<endl;
}
else if (ch=="Desc" or ch=="desc")
{
    cout<<"The Descending order is "<<endl;
}

for(i=0;i<=n-1;i++)
{

    
    cout<<i+1<<" element of the array: ";
    cout<<arr[i]<<endl;
}

for ( i = 0; i <=1; i++)
{
        if (i==1 and (ch=="desc" or ch=="Desc") )
    {
        cout<<"The second largest number in array is: "<<arr[i]<<endl;
    }
    else if(i==1)
    {
        cout<<"The second smallest number in array is: "<<arr[i]<<endl;
    }

}

}
