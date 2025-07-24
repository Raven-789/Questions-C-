#include<iostream>
#include<vector>
using namespace std;

bool isValid(int x, int y, vector <vector <int>> mz,int sz, string res,
             vector <vector<int>> visited){
    
    if(x < 0|| x > sz-1 || y > sz-1 || y < 0  || visited[x][y] == 1 || mz[x][y] == 0){
        return false;
    }
    else{
        return true;
    }
}
  
//  Up = (x-1,y)
//  Down = (x+1,y)
//  Right = (x,y+1)
//  Left = (x,y-1)

//  D L R U

void solve(int x, int y, vector <vector <int>> mz,int sz, string res,
             vector <string>& ans,vector <vector<int>> visited){

    if(x == sz-1 && y == sz-1){
        ans.push_back(res);
        return;
    }

    visited[x][y] = 1;

    //Down
    int newx = x+1;
    int newy = y;
    if(isValid(newx,newy,mz,sz,res,visited)){
        res.push_back('D');
        solve(newx,newy,mz,sz,res,ans,visited);
        res.pop_back();
    }

    // Left
    newx = x;
    newy = y-1;
    if(isValid(newx,newy,mz,sz,res,visited)){
        res.push_back('L');
        solve(newx,newy,mz,sz,res,ans,visited);
        res.pop_back();
    }

    // Right
    newx = x;
    newy = y+1;
    if(isValid(newx,newy,mz,sz,res,visited)){
        res.push_back('R');
        solve(newx,newy,mz,sz,res,ans,visited);
        res.pop_back();
    }

    //Up
    newx = x-1;
    newy = y;
    if(isValid(newx,newy,mz,sz,res,visited)){
        res.push_back('U');
        solve(newx,newy,mz,sz,res,ans,visited);
        res.pop_back();
    }

    visited[x][y] = 0;

}

vector <string > ratMaze(vector <vector<int>> mz, int n){

    int rw = 0, cl = 0;
    string res ;
    vector <string> ans;
    if(mz[0][0] == 0){
        return ans;
    }
    // vector <vector<int>> visited;            MISTAKE
    vector <vector<int>> visited = mz;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    solve(rw,cl,mz,n,res,ans,visited);
    return ans;
}

// Up = (x-1,y)
// Down = (x+1,y)
// Right = (x,y+1)
// Left = (x,y-1)

int main(){
    vector <vector<int>> vec = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    for(auto vec : ratMaze(vec,4)){
        for(auto str : vec){
            cout<< str;
        }cout<<endl;
    }
}

//Space complexity of Binary search and Fibonacci 
//Find the Time and Space Complexity of prev questions of Recursion and do the HW in vid too
