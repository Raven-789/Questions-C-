#include<iostream>
using namespace std;
bool findOccurences(int arr[],int size){
    int occ[size]={__INT_MAX__},o=0,x=0,y=0,z=0,w=0;
    fill_n(occ,size,__INT_MAX__);
    bool chk=false;
    for (int i = 0; i < size; i++)
    {
        chk=false;
        o=0;x=0,y=0;

// checking for unique no.s of the arrays and it also includes i loop but I didn't include it in as it would complicate the code's format--------
        for (int k = 0; k <= i; k++)
        {
            if (arr[k]==arr[i])
            {
                y++;
            }
        }
        if (y==1)
        {
            cout<<arr[i]<<"-->"; //Printing unique elements
 //----------------------------------------------------------------------------------------------------------           
// for the most part the unique elemets finding end here below this is for storing it or printing the occurences of those unique elements
            for (int l = 0; l < size; l++)
            {
                if (arr[i]==arr[l])
                {
                    x++;
                }
            }
            cout<<x<<endl;
            occ[z]=x;
            z++;
        }
//------------------------------------------------------------------------------------------------------------------------------------------------

    //for printing occurences of the elements--------------------------------------------
        // for (int j = 0; j < 10; j++)
        // {
        // // It has 2 loops working (just making sure you don't mess it up)
        //     if (arr[i]==arr[j])
        //     {
        //         x++;
        //     }
            
        // }
        // occ[i]=x;
        // cout<<x;
//-------------------------------------------------------        
        
        // if ((chk)&&(y==0))
        //     {
        //         occ[x]=arr[i];
        //         x++;
        //     }
    
//I didn't include it in the i loop becasue the occ arrays which holds the occurences of unique elements has to be completed first which is only after i loop is finished
    for (int m = 0; m < size; m++)
    {
        w=0;
        for (int n = 0; n< size; n++)
        {
            
            if ((occ[m]!=__INT_MAX__)&&(occ[n]!=__INT_MAX__)&&(occ[m]==occ[n]))
            {
                w++;
            }
            if ((w>1)&&(occ[m]!=__INT_MAX__)&&(occ[n]!=__INT_MAX__))
            {
                return false;
            }
            
        }
        
    }
    if (w==1)
    {
        return true;
    }

        }
    }

int main(){
    int arr[11]={-3,0,1,-3,1,1,1,-3,10,0,0};
    int rishi[6]={1,2,7,7,2,2};
    if (findOccurences(rishi,6))
    {
        cout<<"The elements' occurences are unique (Yes you did it!!!)";
        
    }else{
        cout<<"The elements' occurence are not unique";
    }
    
}