//check how does that code removes duplicates and also check the count condition in every loop
#include<iostream> 
#include<vector>
using namespace std; 

vector <int> spiralPrint(vector <vector <int>>&arr){
    int row=arr.size();
    int col=arr[0].size();
    int total=row*col;
    int count=0;
    vector <int> ans;

    //Index Initialization
    int startingRow=0;
    int endingRow=row-1;
    int startingCol=0;
    int endingCol=col-1;
    while (count<total)
    {
        for (int index = startingCol; index < total && index <=endingCol; index++)
        {
            cout<<arr[startingRow][index]<<" ";
            count++;
            ans.push_back(arr[startingRow][index]);
        }
        startingRow++;
        cout<<endl;
        for (int index = startingRow; index < total &&index <=endingRow ; index++)
        {
            cout<<arr[index][endingCol]<<" ";
            ans.push_back(arr[index][endingCol]);
            count++;
        }
        endingCol--;
        cout<<endl;
        for (int index = endingCol; index<count && index >= startingCol; index--)
        {
            cout<<arr[endingRow][index]<<" ";
            ans.push_back(arr[endingRow][index]);
            count++;
        }
        endingRow--;
        cout<<endl;
        for (int index = endingRow;  index<count &&  index >= startingRow; index--)
        {
            cout<<arr[index][startingCol]<<" ";
            ans.push_back(arr[index][startingCol]);
            count++;
        }
        startingCol++;
        cout<<endl;
    }
    return ans;
}

int main(){
    vector <vector <int>> arr;
    arr={{1,2,3},
         {4,5,6},
         {7,8,9}};

    spiralPrint(arr);
}