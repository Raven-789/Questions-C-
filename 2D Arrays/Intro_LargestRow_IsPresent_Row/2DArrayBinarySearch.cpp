#include<iostream>
#include<vector>
using namespace std; 

bool searchMatrix(vector< vector <int>> &matrix,int target){
    int row=matrix.size();
    int col=matrix[0].size();

    int start =0;
    int end=row*col-1;

    int mid=start+(end-start)/2;

    while (start <=end)
    {
        int element=matrix[mid/col][mid%col];

        if (element==target)
        {
            return 1;
        }
        if (element<target)
        {
            start=mid+1;
        }
        else{
            end=mid+1;
        }
        mid=start +(end-start)/2;
    }
    return 0;
}

bool searchMatrixx(vector< vector <int>> &matrix,int target){
    int row=matrix.size();
    int col=matrix[0].size();

    int rowIndex=0;
    int colIndex=col-1;

    while (rowIndex<row&&colIndex>=0)
    {
        int element=matrix[rowIndex][colIndex];
        
        if (element==target)
        {
            return 1;
        }
        if (element<target)
        {
            rowIndex++;
        }else{
            colIndex--;
        }
        
    }
    return 0;

}

int main(){
    //this matrix is sorted row wise
    vector <vector <int>> arr={{1,3,5,7},
                               {10,11,16,20},
                               {23,30,34,60}};
    cout<<searchMatrix(arr,600);

    //this matrix is sorted row wise and column wise both
    vector <vector <int>> arr1={{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}};

    cout<<searchMatrixx(arr1,24);
}