#include <iostream>
#include <vector>
using namespace std;

// void generateSubsets(int index, vector <int> & nums,vector <int>&current, vector <vector <int>>& result){
    
//     if(index == nums.size()){
//         result.push_back(current);
//         return;
//     }

//     //Exclude current element
//     generateSubsets(index + 1 , nums, current, result);

//     //Include current element
//     current.push_back(nums[index]);
//     generateSubsets(index + 1, nums, current, result);

//     current.pop_back(); // backtrack
// }

// void generatesubsets(int index, vector <int> &nums, vector <int> &current,vector <vector <int>> &result){
//     if (index == nums.size());
//     {
//         result.push_back(current);
//         return;
//     }

//     generatesubsets(index + 1, nums, current, result);

//     current.push_back(nums[index]);
//     generatesubsets(index + 1, nums, current, result);
    
//     current.pop_back();
    
// }









//-----------------------------------------------TRASH-------------------------------------------------------------------TRASH-------------------------------------

//subset without recursion

//     for(int i = 0; i < sz; i++){
//         if(i==0){
//             cout<<"[]"<<endl;
//         }
//         cout<<"[ "<<arr[i]<<" ]"<<endl;
//         if(i != 0){    
//             for( int j = i-1; j >= 0; j--){
//                 cout<<"[ "<<arr[i]<<" "<< arr[j]<<" ]"<<endl;
//             }
//         }
//     }
    
//     cout<<"[";
//     for( int j = 0; j < sz; j++){
//         cout<<" "<<arr[j];
//     }
//     cout<<" ]";
// }



//Subset with recursion


// void subsetRec(int arr[], int sz, int itrI,int itrrI, int itrJ, int lst){

//     if(itrrI == 0 ){//You're a freaking genius for this one
//        itrrI=itrI+1; 
//        itrJ=itrI-1;
//     }

//     if(itrI==sz ){
//         cout<<"[]"<<endl;
//         return;
//     }
//     if( itrI == itrrI){
//        itrrI++;
//        itrJ=itrI-1;
//        cout<<"[ "<<arr[itrI]<<" ]"<<endl;
//     //    lst=lst
//     }

//     if(itrI != sz){
//         if(itrI != 0){
//             if(itrJ != -1){
//                 // if(itrI == itrJ){
//                 //     cout<<"[ "<<arr[itrI]<<" ]"<<endl;
//                 // }else{
//                     cout<<"[ "<<arr[itrI]<<", "<<arr[itrJ]<<" ]"<<endl;
//                 // }
//                 itrJ--;
//                 return subsetRec(arr, sz, itrI, itrrI, itrJ,lst);
//             }
//         }else {//if(itrI == itrJ)
//             cout<<"[ "<<arr[itrI]<<" ]"<<endl;
//         }
//         itrI++;
//         subsetRec(arr, sz, itrI, itrrI, itrJ,lst);
//         if(itrI == sz) cout<<"[";
//     }
//     itrI--;
//     cout<<arr[itrI]<<" ";
//     if(itrI != 0) cout<<", ";
//     if(itrI==0) cout<<"]";
// }

//ask the Mansa sensei for this opinion

//-----------------------------------------------TRASH-------------------------------------------------------------------TRASH-------------------------------------


int print(vector <vector <int>> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j <arr[0].size(); j++){
            cout<<arr[i][j];
        }cout<<endl;
    }
    cout<<"ok";
}

void solve(int index, vector <int> inn, vector <int> out, vector <vector <int>>& ans){
    if(index >= inn.size()){
        ans.push_back(out);
        // for(int i = 0 ; i <= out.size(); i++){
        //     cout<<"["<<out[i]<<"]";
        // }
        return;
    }

    //exclude
    solve(index+1,inn,out,ans);

    //include
    int element=inn[index];
    // cout<<element<<" ";
    out.push_back(element);
    solve(index+1,inn,out ,ans);

}


vector <vector <int>> subsetsRec(vector <int> & arr){
    int index = 0;
    vector <vector <int>> ans;
    // vector <int> inn;
    vector <int> out;
    solve(index,arr,out,ans);
    return ans;
    
    // you can't use this one as there is datatype problems with j as its int and arr also has no elements in one of the vectors
    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout<<arr[i][j];
    //     }cout<<endl;
    // }
    // cout<<"ok";


    //  for(auto subset : ans){
    //     cout<<"[ ";
    //     for(int num : subset)
    //         cout<<num<<" ";

    //     cout<<"]"<<endl;
    // }
    // cout<<"ok";
}





int main(){
    // vector <int> nums={1,2,3};

    // vector <vector <int>> result;
    
    // vector <int> current;

    // generateSubsets(0,nums, current, result);


    // cout<<"All subset: "<<endl;

    // for(auto subset : result){
    //     cout<<"[ ";
    //     for(int num : subset)
    //         cout<<num<<" ";

    //     cout<<"]"<<endl;
    // }




    vector <int> nums= {1,2,3};
    // subsetNoRecursion(nums,4);
    // subsetRec(nums,4,0,0,0,0);
    
    
    // subsetsRec(nums);

    for(auto subset : subsetsRec(nums)){
        cout<<"[ ";
        for(int num : subset)
            cout<<num<<" ";

        cout<<"]"<<endl;
    }
    cout<<"ok";






    // int a = 10;
    // int x = a++;
    // int y = ++a;
    // cout << a << " " << x << " " << y;


}