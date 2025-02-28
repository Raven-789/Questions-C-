#include <iostream>
using namespace std;

int main() {
    // Declaring and initializing an array
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Accessing elements of the array
    cout << "Elements of the array: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Modifying elements in the array
    arr[3] = 100;  // Changing the value of the third element

    // Accessing the modified array
    cout << "\nAfter modifying the third element: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}