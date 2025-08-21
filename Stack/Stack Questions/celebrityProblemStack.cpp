#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


//My Approach ---------------------------------------------------------------------------------------------------------------------------------
//Time Complexity O(n²)
//Space Complexity O(1)


int celebrity(vector <vector<int>> &m , int n){

    int szR = m[0].size();
    int szC = n;
    int cnt = 0;
    bool knownByAll = true;

    for(int i = 0; i < szR; i++){

        for(int j = 0; j < szC; j++){

            //1st condition ignore diagonals
            if(i != j){
                //2nd condition (doesn't know anyone)
                if(m[i][j] == 0){
                    cnt++;// counting the no. of people he/she knows
                }

                //3rd condition (everyone knows him)
                if(cnt == (n-1) ){
                    int k = 0;
                    while(k != n){//checking every row's i th column to check if everybody knows ith row's element or not
                        // if(){
                            if(m[k][i] == 0 && k != i){//LOOK AT THIS CONDITION READ IT TWICE BE BETTER AT THIS OKKK!!!
                                knownByAll = false;
                            }
                            k++;
                        // }
                    }
                }
                if(cnt == (n-1)  && (knownByAll)){
                    return i;
                }
                // cout<<"row "<<i<<" complete"<<endl;
            }
                
        }
        
        cnt = 0;
        knownByAll = true;

    }

    if(cnt == 0 && knownByAll){
        return -1;
    }

}

// His Approach -----------------------------------------------------------------------------------------------------------------------------------------------
// Time Compleixty O(n)
//Space Complexity O(1)

bool knows(vector <vector<int>> &m, int a, int b, int n){

    if(m[a][b] == 1){
        return true;
    }else{
        return false;
    }

}

int celebrityHis(vector <vector<int>> &m , int n){

    stack <int> s;

    //put all elements into stack
    for(int i = 0; i < n; i++){
        s.push(i);
    }

    while(s.size() > 1){

        //take out 2 elements form the stack till there is only 1 element left
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // if a knows b
        if(knows(m,a,b,n)){
            s.push(b);//discard a
        }else{
            s.push(a);//discard b
        }

    }
    int ans = s.top();

    //verify the single elemnent left in stack
    //by checking if all the others know the ith element or not (if yes then return i.... if not then return -1)

    int zeroCount = 0;
    
    //Chekcing the row
    for(int i=0; i<n; i++) {
        if(m[ans][i] == 0 && i != ans)
            zeroCount++;
    }
    
    //your correction in his apporach 
    if(zeroCount != n-1) //its n - 1 as the celeb would know itself so we need to -1 from the size ok as he/she would obv know him/herself ok
        return -1;
    
    //column check
    int oneCount = 0;
    
    //checking the column
    for(int i=0; i<n; i++) {
        if(m[i][ans] == 1 && i != ans) //its n - 1 as the celeb would know itself so we need to -1 from the size ok as he/she would obv know him/herself ok
            oneCount++;
    }
    
    if(oneCount != n-1)
        return -1;
    
    return ans;


}



int main(){

    //1st condition ignore diagonals
    //2nd condition (doesn't know anyone)
    //3rd condition (everyone knows him)


    // see lecture 57 if you don't get the question ok!!
    vector <vector <int>> mat = {{0, 1, 0},
                                 {0, 1, 0},
                                 {1, 1, 0}};

    // //No celebrity condition
    // vector <vector <int>> mat = {{0, 1, 0},
    //                              {0, 0, 0},
    //                              {1, 0, 1}};

    // //2d matrix celeb condition
    // vector <vector <int>> mat = {{0, 0},
    //                              {1, 1}};

    //2d vector no celeb condition
    // vector <vector <int>> mat = {{0, 1},
    //                              {1, 1}};

    int c = celebrity(mat,mat.size()); c == -1 ? cout<<"No celebrity"<<endl :cout<< c <<" is the celebrity!!"<<endl;
    int c2 = celebrityHis(mat,mat.size()); c2 == -1 ? cout<<"No celebrity" :cout<< c2 <<" is the celebrity!!";
}