#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node * down;

        Node(int val){
            data = val;
            next = nullptr;
            down = nullptr;
        }
};

void print(Node * head){
    while(head != nullptr){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"Null\n";
}


// you did correnct by using down -> next -> data and not doing down -> down -> data
Node * flatten(Node * head){

    if(!head ){
        return head;
    }

    Node * dwn = head -> down;
    Node * h2, *nextt;

    // you did correnct by using down -> next -> data and not doing down -> down -> data
    
    while(dwn && (dwn -> next)){// so that we get the last element and not get segmentation fault if there is not down element there too
        dwn = dwn -> next;
    }

    h2 = head;
    nextt = head -> next ;
    // head = head -> next;
    h2 -> next = h2 -> down;
    
    
    if(dwn){
        Node * ans = dwn -> next = (flatten(nextt));
        return head;
    }else{
        Node * ans = h2 -> next = (flatten(nextt));
        return head;
    }

}


int main(){

    Node * n = new Node(5);

    Node * head = n;
    // Node * head =nullptr;

    // you did correnct by using down -> next -> data and not doing down -> down -> data

    //Horizontal part of Unflatten List
    head -> next = new Node(2);
    head -> next -> next = new Node(6);
    head -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next = new Node(1);

    //1st node's children
    // head -> down = new Node(15);
    // head -> down -> down = new Node(25);
    // head -> down -> down -> down = new Node(35);
    // head -> down -> down -> down -> down = new Node(45);
    head -> down = new Node(15);
    head -> down -> next = new Node(25);
    head -> down -> next -> next = new Node(35);
    head -> down -> next -> next -> next = new Node(45);


    // 2nd node's children
    // head -> next -> down = new Node(12);
    // head -> next -> down -> down = new Node(22);
    // head -> next -> down -> down -> down = new Node(32);
    head -> next -> down = new Node(12);
    head -> next -> down -> next = new Node(22);
    head -> next -> down -> next -> next = new Node(32);


    //3rd node's children
    head -> next -> next -> down = new Node(16);
    head -> next -> next -> down -> next = new Node(25);
    
    //4th node's child
    head -> next -> next -> next -> down = new Node(13);

    print(flatten(head));

}