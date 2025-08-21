#include<iostream>
using namespace std;

class TwoStack {

    public:
        int * arr;
        int top1;
        int top2;
        int size;

        

        TwoStack (int size){
            this -> size = size;
            arr = new int [size];
            top1 = -1;
            top2 = size ;// you don't need to +1 in size as arrays start from 0 and size is already gonna be +1 by itslef ok
        }

        void push1(int num){
            // if((top1 + top2) - size > 1){ // this condition is wrong you can give the whole class to gpt and then ask why is this worng but you're smart soo figure it yourself hint: try putting in the first few vals you'll get why 
            if(top2 - top1 > 1){
                top1++;
                arr[top1] = num;
            }else{
                cout<<"1st Stack Overflow!"<<endl;
            }
        }

        void push2(int num){
            // if((top1 + top2) - size > 1){ // this condition is wrong you can give the whole class to gpt and then ask why is this worng but you're smart soo figure it yourself hint: try putting in the first few vals you'll get why 
            if(top2 - top1 > 1){
                top2--;//as its starting from the other end of the same array
                arr[top2] = num;
            }else{
                cout<<"2nd Stack Overflow!"<<endl;
            }
        }

        int pop1(){
            if(top1 == -1){
                cout<<"Stack Underflow"<<endl;
                return -1; //gpt got this one if you don't use it its gonna haywire the function
            }else{
                int ans = arr[top1];
                top1--;
                cout<< "element "<<ans << " is popped"<<endl;
                return ans;
            }

        }

        int pop2(){
                if(top2 == size){
                cout<<"Stack Underflow"<<endl;
                return -1; //gpt got this one if you don't use it its gonna haywire the function
            }else{
                int ans = arr[top2]; 
                top2++;//as its starting from the other end of the same array
                cout<< "element "<<ans << " is popped"<<endl;
                return ans;
            }
        }

        ~TwoStack() {
        delete[] arr; // clean up memory
    }

};

int main() {
    //gpt gave the int main ok so your my comments will be in that way ok (you get it I know)

    //1st approach is to divide the array into 2 equal halves which is not efficient as space is not utilized properly (put it in gpt if you don't get it)
    //2nd approach is to use 2 pointers top1 and top2 this uses space efficiently


    TwoStack ts(10);  // create a TwoStack with size 10

    // Push elements into first stack
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements into second stack
    ts.push2(100);
    ts.push2(90);
    ts.push2(80);

    // Pop from both stacks
    cout << ts.pop1() << endl;  // should print and return 15
    cout << ts.pop2() << endl;  // should print and return 80

    // Test underflow from empty stack
    for(int i = 0; i < 5; i++) ts.pop1();  // some of these will underflow (I checked it and its 3 of them) 

    // Test overflow
    ts.push1(1);
    ts.push1(2);
    ts.push1(3);
    ts.push1(4);
    ts.push1(5);  // may overflow depending on how full it is (ohh this is 1st stack )
    ts.push2(6);  // push2 when nearly full (and this is 2nd)
    ts.push2(6);
    ts.push2(6);
    ts.push2(6);// it overflows here once
    ts.push2(6);
    return 0;
}