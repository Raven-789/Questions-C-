#include<iostream> 
using namespace std;

#define PI 3.14


// Function-like Macro definition
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main() {

    int a = 18, b = 76;

    // printf("Minimum: %d", min(a, b));
    cout<<"Minimum: "<< min(a, b)<<endl;

    int r = 5;
    //double pi = 3.14;

    double area = PI * r * r;

    cout << "Area is " << area << endl;

    return 0;
}