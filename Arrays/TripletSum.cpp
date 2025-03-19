#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void tripletSum(vector <int>arr,int s){
    vector<vector <int>>ans;
    for (int i = 0; i < arr.size(); i++){
        // if j loop starts from 0 it repeates the arrays so we start 1 after i
        for (int  j = i+1; j < arr.size(); j++){ 
        //we're initializing k loop from j+1 as we don't want elements to repeat themselves in output
            for (int k = j+1; k < arr.size(); k++){ 
                if ((arr[i]+arr[j]+arr[k])==s){//here we're checking if the triplet's sum is correct or not
                //--------------------------------------------
                //this is longer way you can write it in shorter way optimizing it as shown in
                //  next dotted line
                    // vector <int>temp;
                    // temp.push_back(arr[i]);
                    // temp.push_back(arr[j]);
                    // temp.push_back(arr[k]);
                //--------------------------------------------
                    vector <int>temp={arr[i],arr[j],arr[k]};
                    // ans.push_back(temp);// this is commented because we've to check and as 
                    // it was your mistake too that's why

                    sort(temp.begin(), temp.end()); // Sort to handle duplicate order cases
                    
                    // Check if temp already exists in ans using normal for loop
                    bool found = false;
                    for (int m = 0; m < ans.size(); m++) {
                        if (ans[m] == temp) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    int sz=ans.size();
    for (int l = 0; l < ans.size(); l++)
    {
        cout<<"["<<ans[l][0]<<","<<ans[l][1]<<","<<ans[l][2]<<"]"<<endl;
    }
}


int main(){
    vector <int> arr={10 ,5 ,5 ,5 ,2};
    tripletSum(arr,12);
}

