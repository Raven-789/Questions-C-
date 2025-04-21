#include<iostream>
using namespace std;

// always start making args default from the rightmost one or else it gives an error and it should be continous okay you'll get it
void print(int arr[], int n  , int start = 0) { 

    for(int i = start; i<n; i++) {
        cout << arr[i] << endl;
    }

}

int main() {

    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2);


    return 0;
}