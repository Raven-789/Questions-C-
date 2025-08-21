#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;

class SpecialStack{

    public:
        int size;
        int curr;
        int mini;
        int * arr;

        SpecialStack(int S){
            this -> size = S;
            arr = new int[S];
            curr = -1;
            mini = INT_MAX;//limits.h
        }


        void push(int data){

            if(size - curr < 1){//Overflow condition

                cout<<"Stack Overflow!!"<<endl;
            }
            else if (mini == INT_MAX){// for 1st element normal push and "mini" is updated

                curr++;
                arr[curr] = data;
                mini = data;//this line is only for 1st element that's why we couldn't merge the else condtion in here
            }
            else{//for all other elements

                if(data < mini ){//comparing the new data with current minimum of the stack ok

                    curr++;
                    int val = 2* data - mini;// this stores the prev min (val) in the array and if we want the prev. min we do val = 2* mini - temp;
                    arr[curr] = val;
                    mini = data;
                    
                }
                else{//else normal push if mini is still the smallest

                    curr++;
                    arr[curr] = data;
                }

            }

        }

        int pop(){

            if(curr < 0){

                cout<<"Stack Underflow!!"<<endl;
            }
            int temp = arr[curr];//storing the current val as we'll pull back the current pointer(popping the element)
            // curr--;
            if(arr[curr] > mini){

                curr--;//pulling back the current pointer (which is pointing at top of stack)
                // curr --;//pulling back the curr conceptually elininating the elminating the element as stack is continious so we can push new val in that eliminated element's index
                return temp;//returning the popped element
            }
            else{

                int poppedElement = mini;
                curr--;
                int val = 2* mini - temp;//giving the next smallest element
                mini = val;
                return poppedElement;//returning the popped element
            }

        }

        int top(){

            if(curr == -1){
                return -1;
            }else{
                if (arr[curr] < mini) {//as we've pushed the formula instead of element so we'll push mini
                    
                    return mini;
                }
                else{

                    return arr[curr];
                }
            }
        }

        int getMin(){
            return mini;
        }
};


int main(){

    SpecialStack s(5);

//  Formulas used
//  for push -> Formula_val = (2 * current mini) - prev_mini
//  for pop -> prev_mini = (2 * current mini) - Formula_val
//  

    s.push(7);
    cout<<s.top()<<endl;
    s.push(5);
    s.push(3);
    // s.push(9);
    cout<<s.top()<<" top"<<endl;
    cout<<s.pop()<<" is popped"<<endl;
    cout<<s.pop()<<" is popped"<<endl;
    cout<<s.top()<<" top"<<endl;
}