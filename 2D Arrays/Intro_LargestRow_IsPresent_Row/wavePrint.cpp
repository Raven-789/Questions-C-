#include<iostream> 
#include<vector>
using namespace std; 

vector <int> wavePrint(vector <vector <int>> &arr, int nrows,int mcols){
    //it gives a reverse wave see it carefully
    vector <int> temp;
    for (int cols = 0; cols < mcols; cols++)
    {
        if (cols & 1)//if column is odd 
        {
            for (int rows = 0; rows < nrows; rows++)
            {
                cout<<arr[rows][cols]<<" ";
                temp.push_back(arr[rows][cols]);
            }
            
        }else{
            for (int rows = nrows-1; rows >=0; rows--)
            {
                cout<<arr[rows][cols]<<" ";
                temp.push_back(arr[rows][cols]);
            }
        }
        cout<<endl;
        
    }
    return temp;
}

int main(){
    vector <vector <int>> arr;
    //it gives a reverse wave see it carefully
    arr={{1,2,3},
         {4,5,6},
         {7,8,9}};
    wavePrint(arr,3,3);
}