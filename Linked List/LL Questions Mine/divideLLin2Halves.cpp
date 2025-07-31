#include<iostream>
#include<utility>
using namespace std;

//Time Complexity O(n)
//Space Complexity O(1)

class Node{
    public:
        int data;
        Node *next;

        //constructor
        Node(int d){
            this -> next = NULL;
            this -> data = d;
        }
};


void print(Node *& tail){

    Node * temp = tail;

    if(tail == NULL){
        cout<<"List is Empty."<<endl;
    }
    else{
        do{
            cout<< temp -> data <<" -> ";
            temp = temp -> next ;
        }while(tail != temp);
        cout<<"Repeats..."<<endl;
    }
}


int getlen(Node * head){

    Node * h = head;
    int cnt = 0;

    while(h != head){
        cnt++;
        h = h -> next;
    }
    return cnt;
}



Node * getMidOfLL2nd(Node * head){

    Node * slow = head;
    Node * fast = head -> next; // this is NEW HERE READ THIS ONE 

    while(fast != head ){
        fast = fast -> next;
        if(fast != head){// this condition is also NEW READ THIS ONE TOOO 
            fast = fast -> next;
        }
        slow = slow -> next;
    }

    return slow;

}

pair<Node * , Node *> divideInTwo(Node * head){

    // typedef struct N{
    //     Node * a;
    //     Node * b;
    // }Ptr_Pair;

    Node * first, * firLast, * second, * sec2;

    first = getMidOfLL2nd(head);
    second = first -> next;
    sec2 = second;

    while(sec2 -> next != head){
        sec2 = sec2 -> next;
    }
    
    // cout<<sec2 -> data<<" " << second -> data<< endl;
    sec2 -> next = second;//Pointing last node of the 2nd half of the Main List to Mid of the Main List

    //Connecting first list's last element to head (aka the 1st element)
    first -> next = head;
    first = first -> next;
    // cout<< head -> data << " "<< first -> data<<endl;
    
    pair<Node *, Node *> ptrs;
    ptrs.first = first;
    ptrs.second = second;
    return ptrs ;
}


int main(){

    Node * n = new Node(1);

    Node * head =n;
    // Node * head =nullptr;


    head -> next = new Node(4);
    head -> next -> next = new Node(2);
    head -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next -> next -> next -> next = new Node(1);
    head -> next -> next -> next -> next -> next -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next -> next -> next -> next -> next -> next = head;// created a cycle

    pair<Node*,Node*> ptr = divideInTwo(head);
    print(ptr.first);
    cout<<ptr.first -> data<< " - "<<ptr.second -> data<<endl;
    print(ptr.second);


}