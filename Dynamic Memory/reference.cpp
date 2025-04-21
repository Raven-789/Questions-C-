#include<iostream>
using namespace std;

//Bad practice as its returning a ref variable. You never do that as the lifespan of that variable is only till the control is to the function
int& func(int a) {
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int n) {//Bad practice as its returning a pointer. You never do that as the lifespan of that variable is only till the control is to the function
    int* ptr = &n;
    return ptr;
}

void update2(int& n) {
    n++;
}

void update1(int n) {
    n++;
}

int main() {

    /*
    int i = 5;

    //create a ref variable 

    int& j = i;

    cout << i << endl; 
    i++;
    cout << i << endl; 
    j++;
    cout << i << endl; 
    cout << j << endl;
    */

   int n = 5;
   
   cout << "Before " << n << endl;
   update2(n);
   cout << "After " << n << endl;

    fun(n);

    return 0;
}