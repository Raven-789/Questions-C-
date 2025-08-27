#include<iostream>
#include<cstring>
#include<bits/stdc++.h> //Use this one for all structures
using namespace std;


//Time Complexity O(1)
//Space Complexity O(n)
class Queue{
    public:
        int * arr;
        int rear;
        int qfront;
        int size;//size was not taken from user in question

        Queue(){
            
            size = 5;
            qfront = 0;
            rear = 0;
            arr = new int[size];
            // int sz = sizeof(arr);  //can't be used in dymnic memeory ok
            // fill_n(arr,size,-111111);//for marking purposes 
            // cout<<"array elements: "<<endl;
            // for(int i = 0; i < size; i++){
            //     cout<< arr[i] <<" ";
            // }
        }


        void enqueue(int data){

            if(rear == size -1) {
                cout<<"Queue Full"<<endl;
            }else{
                    
                arr[rear] = data;
                rear++;
            
            }
            
        }

        int dequeue(){

            //queue empty condition
            if(rear == qfront ){
                rear = qfront = 0;//reset if queue is empty in a middle index 
                cout<<"Queue Empty"<<endl;
            }else{

                int ele = arr[qfront];
                qfront++;
//------------------------This condtion helps in full memeory utilization (read it you didn't get it the 1st time)------------------------------------------------------------------------
                if(qfront == rear){//this condition is if when we pop all the elements and rear and front end up at mid of array then we've to reset them you know to 0
                    rear = qfront = 0;
                }
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                return ele;

            }

        }

        int front(){

            // cout<<"array elements: "<<endl;
            // for(int i = 0; i < size; i++){
            //     cout<< arr[i] <<" ";
            // }
            if(rear == qfront){
                return -1;
            }
            int ele= arr[qfront];

            return ele;

        }

        bool isEmpty(){
            if((qfront == 0 && rear == size ) || (rear == qfront) ){
                return true;
            }else{
                return false;
            }
        }
};

int main(){

    // in normal queue if you pop a few elements (considering it has elements okk) and then push the space 
    // will be reduced for the elements (try it if you don't get it) this is overcomed by circular queue

    Queue q;
    cout<<q.isEmpty()<<endl;
    cout<<q.front()<<endl;
    q.enqueue(10);
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    cout<<q.isEmpty()<<endl;


    q.enqueue(30);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    // q.dequeue();
    q.enqueue(10);
    q.enqueue(60);
    q.enqueue(20);
    q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    cout<<q.front()<<endl;


}