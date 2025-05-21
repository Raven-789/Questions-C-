#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper){
    if(n==1){
        cout<<"Move dist 1 from "<<source<<" to "<<destination<<endl;
        return;
    }

    //Step 1: Move n-1 disks from source to helper
    towerOfHanoi(n -1, source, helper, destination);

    //Step 2: Move the nth disk from source to destination
    cout<<"Move distk "<< n << " from "<<source << " to "<<destination<<endl;

    //Step 3: Move n-1 disks form helper to destinatioin
    towerOfHanoi(n-1, helper, destination, source);
}

int main(){
    int n ;
    cout<<"Enter number of disks: ";
    cin>>n;

    towerOfHanoi(n,'A','C','B');// A = source, C = destination, B = helper
    
}