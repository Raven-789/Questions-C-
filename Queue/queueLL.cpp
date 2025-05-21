#include<iostream>
#include<list>
using namespace std;

class Queue{
    list <int> lst;

    public:
        //Enqueue
        void enqueue(int x){
            lst.push_back(x);
        }

        //Dequeue
        void dequeue(){
            if(lst.empty()){
                cout<<"Queue Underflow \n";
                return;
            }
            lst.pop_front();
        }

        //Front element
        int front(){
            if(lst.empty()){
                cout<<"Queue is Emtpy \n";
                return -1;
        }
        return lst.front();
    }

    //Check empty
    bool isEmtpy(){
        return lst.empty();
    }

    //Size
    int size(){
        return lst.size();
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout<<"Front : "<<q.front()<<endl;

    q.dequeue();
    cout<<"Front after dequeue: "<<q.front()<<endl;
    return 0;
}