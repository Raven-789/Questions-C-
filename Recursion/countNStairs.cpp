#include<iostream>
using namespace std;

//It'll give TLE we need to solve it from Dynamic Programming

int countDistinctWays(int nStairs) {
    //base case
    if(nStairs<0)
        return 0;
    
    if(nStairs==0)
        return 1;
    
    //Recursive Relation
    int ans=countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    return ans;
}

int main(){
    cout<<countDistinctWays(5);
}