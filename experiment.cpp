#include<iostream>
#include<vector>
using namespace std;

int main(){
    int temp[10] = {1,2,3,5,7,82,7,2,7,1};
    int *ptr = &temp[0];
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << sizeof(temp) << endl;
    cout << sizeof(ptr) << endl;      // 4 or 8
    cout << sizeof(*ptr) << endl;
    cout << sizeof(&ptr) << endl;       // 4 or 8
}