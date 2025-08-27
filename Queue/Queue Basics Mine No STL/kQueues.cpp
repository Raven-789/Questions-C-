#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;
//lecture 61
//use nstacks file as an refernece it as detailed explanation

class kQueues{

    public:
        int *arr;
        int *front;
        int *rear;
        int freeSpot;
        int * next;
        int K,S;


        //Constructor
        kQueues(int K, int S){

            this -> K = K;
            this -> S = S;
            arr = new int[S];
            front = new int [K];
            rear = new int [K];
            next = new int [S];
            freeSpot = 0;
            memset(front, -1, K * sizeof(int));
            memset(rear, -1, K * sizeof(int));
            for(int i = 0; i < S; i++){// we store 1+ in every index so that we can track back the previous freespot
                next[i] = i + 1;// filling the next free spaces in next array
            }
            next[S-1] = -1;// for last element (I thought that I could use memset first and fill it all with -1 and then use loop to update it with next free vals but it costs a lot more as firstly memset has its own time and then loop too soo this )

            // for(int i = 0; i < S; i++){
            //     cout<<next[i];
            // }cout<<"ok"<<endl;

        }

        bool enqueue(int X, int M){

            //overflow condition
            if(freeSpot == -1){
                cout<<"K Queues Overflow ";
                return false;
                cout<<endl;
            }

            // find index
            int index = freeSpot;

            //update freespot next is storing the free indexes in arr ok (for conceptual purposes) going to next element of its 
            // respected queue not the main arr ok
            freeSpot = next[index];

            //HERE IT GETS DIFFERENT -------------------------------------------------------------------------------------------------

            // if its the first element
            if(front[M-1] == -1){
                front[M-1] = index;
            }else{//if its not the fist element LINK IT WITH PREVIOUS REAR OF THE QUEUE
                //this line means in the prev rear's index (which is 0 at first) store current rear's index for popping purpose
                next[rear[M-1]] = index;//this the line I'm talkign about in "update next"
            }

            //Update next
            next[index] = -1;// we're marking next as -1 which shows there is only 1 element (and its occupied and its the
                            //  front soo we can use it pop) in the queue but it'll be updated once we add more the it'll
                            //  hold the index of new rear element

            rear[M-1] = index;

            //push the value
            arr[index] = X;

        }

        int dequeue(int M){

            //Underflow Condition
            if(front[M-1] == -1){
                cout<<"K Queue Underflow ";
                return -1;
                cout<<endl;
            }

            // create index
            int index = front[M-1];

            // Update front (popping the element)
            front[M-1] = next[index];

            //freeing the next arr's slot for other elements 
            next[index] = freeSpot;//storing the freespot (which is showing and index to current freespot) int next index
                                    //  (the index from where we just popped)

            //pop the element now by making it the freespot
            freeSpot = index;//now making the current index from whihc we just popped a freespot (the index's  next[index] 
                                //stores the index of next freespot... see the prev line for more context ok)

            return arr[index];

        }

};


int main(){

    //use nstacks file as an refernece it as detailed explanation

    kQueues q(3,10);

    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;


}