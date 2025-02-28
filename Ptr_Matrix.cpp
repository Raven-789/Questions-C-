#include <iostream>
using namespace std;

int main() {
    int **p, nr, nc, r, c;

    // Input number of rows and columns
    cout << "Enter number of rows and columns: ";
    cin >> nr >> nc;

    // Allocate memory for the array of pointers (rows)
    p = new int*[nr];

    // Allocate memory for each row (columns)
    for (r = 0; r < nr; r++) {
        p[r] = new int[nc];
    }

    // Input values into the 2D arra y
    for (r = 0; r < nr; r++) {
        for (c = 0; c < nc; c++) {
            cout << "Enter element at [" << r << "][" << c << "]: ";
            cin >> p[r][c];
        }
    }

    // Output values of the 2D array
    cout << "Elements are:\n";
    for (r = 0; r < nr; r++) {
        for (c = 0; c < nc; c++) {
            cout << p[r][c] << " ";
        }
        cout << endl;
    }

    // Deallocate the memory
    for (r = 0; r < nr; r++) {
        delete[] p[r];  // Deleting each row
    }
    delete[] p;  // Deleting the array of pointers

    return 0;
}