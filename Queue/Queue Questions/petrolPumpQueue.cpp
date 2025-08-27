#include<iostream>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;
//Lecture 61 circular pump

struct petrol_pump {
    int petrol;   // amount of petrol at the station
    int distance; // cost to next station
};


// My approach-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//Time Complxity O(n²) (2 times traversal of each element in worst case)
//Space Compelxity O(1)
int tour(vector <petrol_pump > p, int n){// you were doing this " int tour(vector <petrol_pump > p[], int n){ " [ ] was a problem as it was a vector you know

    int ans= -1, possible = -1,extra = 0, i = 0, f,d;
    bool chk =false;
    while(i != ans){

        d = p[i].distance;
        f = p[i].petrol;
        possible = (f+extra) - d;
        if(possible > 0){

            
            possible = (f+extra) - d;
            extra = possible;
            if(ans == -1){
                ans = i;
            }

        }else{
            
            if(possible < 0 ){// to check if the last element is the final solution
                ans = -1;
            }
            possible = -1;
            extra = 0;
            if(i == n -1 || chk ){
                break;
            }
            
        }

        if(possible > 0 && i == n-1){
            i = 0;
            chk = true;
        }else{
            i++;
        }

    }
    return ans;
}


// his Approach-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//wayyyy better
//Time Complxity O(n)
//Space Compelxity O(1)
//Lecture 61 circular pump

int tour2nd(vector <petrol_pump > p, int n){

    int deficit = 0, balance = 0, start = 0;
    for(int i = 0; i < n; i++){

        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit += balance;// to travel only n times not 2n times we stored the deficit as if we can't reach a pump even with balance of prev pumps we can't reach it soo we stored the deficit ok
            start = i +1;
            balance = 0;
        }

    }

    if(deficit + balance >= 0){
        return start;
    }else{
        return -1;
    }

}




int main(){

    vector<petrol_pump> stations = {
                                    {4, 6},
                                    {5, 6},
                                    {7, 3},
                                    {4, 5}
                                    };



    // vector<petrol_pump> stations = {
    //     {1, 3},
    //     {2, 4},
    //     {3, 5},
    //     {4, 1},
    //     {5, 2}
    // };
         
    // vector<petrol_pump> stations = {
    //     {3, 7},
    //     {9, 6}
    // };

    // vector<petrol_pump> stations = {
    //     {5, 4},
    //     {1, 4},
    //     {2, 1},
    //     {3, 5},
    //     {4, 1}
    // };

    int sz = stations.size();
    cout << stations[1].distance<<endl;
    cout<<"Answer is: "<<tour(stations , sz)<<endl;
    cout<<"Answer is: "<<tour2nd(stations , sz);

}