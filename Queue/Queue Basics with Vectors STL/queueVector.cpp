#include<iostream>
#include<vector>
using namespace std;

class Queue{
    vector <int> v;

    public:
        //Enqueue (insert at back)
        void enqueue(int x){
            v.push_back(x);
        }

        //Dequeue (remove from front)
        void dequeue(){
            if(v.empty()){
                cout<<"Queue Underflow \n";
                return;
            }
            v.erase(v.begin());//costly operation
        }

        //Front element
        int front(){
            if(v.empty()){
                cout<<"Queue is EMtpy \n";
                return -1;
            }
            return v[0];
        }

        // check empty
        bool isEmpty(){
            return v.empty();
        }

        //Size
        int size(){
            return v.size();
        }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<"Front: "<<q.front()<<endl;

    q.dequeue();
    cout<<"Front after dequeue: "<<q.front()<<endl;

    return 0;
}

