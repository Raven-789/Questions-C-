// Odd row index element will go to odd column index element and vice versa for row element
//  ok it may not be the correct word but you get it ok 

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    int r1=0,c1=0,r2=0,c2=0,chk=0;
    while ((r1<row && c1<col) && (r2<row && c2<row))
    {
        // cout<<matrix[r1][c1++];
        // cout<<matrix[r2++][c2];
        swap(matrix[r1][c1++],matrix[r2++][c2]);
        // cout<<matrix[r1][c1];
        // cout<<matrix[r2][c2];
        
        if ( c1==col && r2==row && chk<row-1)
        {
            r1++;c2++;chk++;
            r2=c1=0+chk;
        }
        
        
    }
    c1=r1=0;
    
    while (r1<row)
    {
        c2=col-1;
        while (c1<c2)
        {
            swap(matrix[r1][c1++],matrix[r1][c2--]);
        }
        r1++;c1=0;

    }
    
    
    
}

void print(vector<vector <int>> &arr){
    
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

int main(){
    // vector<vector <int>> arr={{1,2,3}
    //                          ,{4,5,6}
    //                          ,{7,8,9}};
    vector<vector <int>> arr={{5,1,9,11},
                              {2,4,8,10},
                              {13,3,6,7},
                              {15,14,12,16}};
rotate(arr);
print (arr);

                            //  {{1,4,7}
                            //  ,{2,5,8}
                            //  ,{3,6,9}}
}