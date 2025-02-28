#include <iostream>

using namespace std;

int main() {
    int variable = 42; // A regular integer variable
    int* pointer = &variable; // A pointer that stores the address of 'variable'

    // Output the value of 'variable' and the address stored in 'pointer'
    cout << "Value of variable: " << variable << endl;
    cout << "Address of variable: " << &variable << endl;
    cout << "Pointer points to address: " << pointer << endl;
    cout << "Value at the address pointer points to: " << *pointer << endl;

    // Modifying the value using the pointer
    *pointer = 100; // Change the value of 'variable' through the pointer

    // Output the modified value of 'variable'
    cout << "Modified value of variable: " << variable << endl;

    return 0;
}