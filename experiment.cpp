#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> vec={1,2,3,4};
    vector <int> vec1={};
    vec1=vec;
    for(int i = 0;i < 4; i++){
        cout<<vec1[i];
    }
}