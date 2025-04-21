#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {
    
    //formulas :-
    // arr[i] =*(arr+i)
    // i[arr]=*(i+arr) // as arr is what give you address if you cout<<arr; you know so *(arr) gives the value inside that address (1st element in default after that you can add no. to it to access other elements of arr)
    
    char ch='q';
    cout<<sizeof(ch)<<endl;

    char *c=&ch;
    cout<<sizeof(c)<<endl;

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];
    int *i=new int;

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    delete []arr; // deallocation of array
    delete i;//deallocation of single variable


    cout << "answer is "<< ans << endl;


    //case 1
    while(true) {
        int i = 5; //we're initialzing a new int everytime in the loop so it'll not crash but it'll go on forever
    }
    
//  DO NOT RUN THIS CASE SYSTEM WILL CRASH SEE IT FRIST AND GET IT BUT DO NOT RUN IT    
//  case 2 
//     while(true) {
//         int* ptr = new int;// here we're creating new ptr everytime in Stack memory so it won't crash cause' of that 
//  // but it'll crash cause of new int as its creating new int (4 bytes) everytime in loop in Heap Memory 
//  // So it'll crash cause' of new int not int * ptr okay
//     }
}