#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


//MY Approach --------------------------------------------------------------------------------------------------
//Time Compelxity O(n*k)
//Space Complexity O(1)

int sumOfMinAndMaxOfSubArrOfSizeK(int arr[], int n, int k){

    int min = INT_MAX, max = INT_MIN,sum = 0;

    // for(int i = 0; i < n; i++){
        for(int i = 0; i+k <= n; i++) {

        // for(int j = i; j+k < n ; j++){
        for(int j = i; j < i+k && i+k <= n; j++) {

            // if(arr[j] < INT_MIN){// this makes the code work in such a way that control doesn't even enters the inner loop
            if(arr[j] < min){
                min = arr[j];
            }
            // if(arr[j] > INT_MAX){// this makes the code work in such a way that control doesn't even enters the inner loop
            if(arr[j] > max){
                max = arr[j];
            }

        }

        sum += min + max;
        min = INT_MAX;
        max = INT_MIN;


    }

    //     for(int i = 0; i < n; i++) {
    //     // int min = INT_MAX, max = INT_MIN;

    //     for(int j = i; j+k < n; j++) {
    //         if(arr[j] < min) min = arr[j];
    //         if(arr[j] > max) max = arr[j];
    //     }

    //     sum += (min + max);
    // }

    return sum;
}


//His Approach ------------------------------------------------------------------------------------------------------------------------
//Time Compelxity O(n)
//Space Complexity O(1)
//My version of his approach is wrong 

// int sumOfMinAndMaxOfSubArrOfSizeKHis(int arr[],int n, int k){

//     deque <int> dqMax, dqMin;
//     int min = INT_MAX, max = INT_MIN,sum = 0;

//     for(int i = 0; i < k; i++){

        // ❌ Mistake 1: You manually compare with `min` and `max`, and update them directly.
        // ❌ But you're supposed to maintain increasing/decreasing order in the deques, not just track min/max values.
        // ❌ Also, if an earlier element is no longer useful, you should pop it from the deque.
        // ❌ This leads to incorrect deque state

//         //adding the elements of 1st window
//         //these deque have more elements in increasing and decreasing order respectively
//         if(arr[i] < min){   
//             dqMin.push_back(i);
//             min = arr[i];
//         }
//         if(arr[i] > max){
//             dqMax.push_back(i);
//             max = arr[i];
//         }

//     }

    // ❌ Mistake 2: You add arr[dqMax.back()] + arr[dqMin.back()]
    // ❌ But correct values are at dqMax.front() and dqMin.front()
    // ✅ Because front of deque always has the max/min for the current window

//     sum += arr[dqMax.back()] + arr[dqMin.back()];
    
    
//     for(int i = k; i < n; i++){

//         // min = INT_MAX, max = INT_MIN;
        // ❌ Mistake 3: Bug in deque popping logic
        // ❌ You pop from dqMax in both cases — this is wrong!
        // ✅ You should pop from dqMin if min element is out of the window

//         if(!dqMax.empty() && (i - dqMax.front()) >= k){//this can be empty ok check if you don't get it
//             dqMax.pop_front();
//         }
//         if(!dqMin.empty() && (i - dqMin.front()) >= k){//this can also be empty check if you don't get it
//             dqMax.pop_front();
//         }

        // ❌ Mistake 4: Same as in first loop — again you're updating min/max manually
        // ❌ You’re not maintaining proper deque order, which is the whole point


//         if(arr[i] < min){
//             dqMin.push_back(i);
//             min = arr[i];
//         }
//         if(arr[i] > max){
//             dqMax.push_back(i);
//             max = arr[i];
//         }
        

        // ❌ Mistake 5: Again using .back() instead of .front()

//         sum += arr[dqMax.back()] + arr[dqMin.back()];
//     }

//     return sum;
// }


int solve(int *arr, int n, int k) {
    deque<int> maxi, mini;
    int ans = 0;

    for(int i = 0; i < k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
    }

    ans += arr[maxi.front()] + arr[mini.front()];

    for(int i = k; i < n; i++) {
        if(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        if(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}




int main(){

    int arr[] = {2, 5, -1, 7, -3, -1, -2};

    int sz = sizeof(arr)/sizeof(arr[0]);
    // cout<<sumOfMinAndMaxOfSubArrOfSizeK(arr,sz,4)<<endl;
    cout<<sumOfMinAndMaxOfSubArrOfSizeKHis(arr,sz,4)<<endl;

}