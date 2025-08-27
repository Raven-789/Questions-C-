#include<iostream>
#include<queue>
#include<deque>
using namespace std;

void printvec(vector <int> v){

    for(auto ele : v){
        cout<<ele<<" ";
    }cout<< "ok" <<endl;

}


//My Approach ---------------------------------------------------------------------------------------------------------------------------------------------
//Time Compleixty O(n)
//Space Complexity O(n)

vector<int> kthwindow(int arr[], int sz, int k){

    deque <int> dq;
    vector <int> ans;


    if(sz < k){
        ans.push_back(0);
        return ans;
    }

    for(int i = 0; i <= sz; i++){

        if(dq.size() == k){
            while(!dq.empty()){//!dq.empty()            dq.size() <= k && dq.size()
                
                if(dq.front() < 0){
                    ans.push_back(dq.front());
                    break;
                }else if(dq.front() >= 0 && dq.size() == 1){
                    ans.push_back(0);
                    dq.pop_front();
                }else{
                    dq.pop_front();
                }
            }
        }

        while(!dq.empty()){
            dq.pop_back();
        }

        printvec(ans);

        if(i+k <= sz){
            for(int j = i; j < i+k; j++){
                dq.push_back(arr[j]);
            }
        }else{
            break;
        }

        
    }

    

    return ans;
}


//His Approach --------------------------------------------------------------------------------------------------------------------------------------------

vector<int> printFirstNegativeInteger( int A[],
                                              int N, int K) {

    deque <int> dq;
    vector <int> ans;
    //first window
    // pushing all -ve no.s in dq and when I pop from front it'll be the first -ve int as we wanted
    for(int i = 0; i < K; i++){

        if(A[i] < 0){   
            dq.push_back(i);
        }

    }
    //if there's is nothing in the dq then we push 0 for the first
    if(!dq.empty()){
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }

    //now for processing the other K windows

    for(int i = K; i < N; i++){

        //removal of elements which aren't in the window now
        //you FORGOT THIS CONDITION OKKK!!!
        if(!dq.empty() && (i - dq.front()) >= K){//checking if the window size is desired dq.front() <= i - K
            dq.pop_front();
        }

        //now for addition of new element in the window
        if(A[i] < 0 ){
            dq.push_back(i);//pushing the index not the element
        }

        //now to put final answer in ans
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }

    }

    return ans;
}


int main(){

    // int arr[5] = {-8, 2, 3, -6, 10};
    int arr[8] = {12, -1, -7, 8, -15, 30, 16, 28};
    // int arr [5] = {1, 2, 3, 4, 5};
    // int arr[7] = {-5, -3, -1, 2, 4, -2, 7};
    // int arr[5] = {0, 0, 0, 0, 0};
    // int arr[8] = {1, -1, 2, -3, 4, -5, 6, -7};
    // int arr[7] = {1, -1, 2, 0, -5, 3, -2};
    // int arr[] = {-10, -20, 10, 20, -30, 40};
    // int arr[] = {-1, -2, -3, -4, -5};
    // int arr[] = {1,2,3};

    int sz = sizeof(arr)/sizeof(arr[0]);
    // cout<<"Final Answer"<<endl;
    printvec(kthwindow(arr,sz,3));
    cout<<"2nd ONE"<<endl;
    printvec(printFirstNegativeInteger(arr,sz,3));
    

}