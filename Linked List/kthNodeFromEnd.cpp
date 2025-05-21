#include<iostream>
using namespace std;

class Node{
    public:
        int data ;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

Node* findKthFromEnd(Node *head, int k){
    Node *first=head;
    Node *second = head;

    for(int i = 0; i < k ; i++){
        if(first == nullptr) return nullptr;
        first = first -> next;
    }

    while( first != nullptr){
        first= first -> next;
        second = second -> next;
    }

    return second;
}

int main(){
    //List: 10 ->20 ->30 ->40 ->50

    Node * head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = new Node(50);

    int k=2;
    Node *result = findKthFromEnd(head,k);
    if(result != nullptr)
        cout<<"The "<<k<<"nd node from end is: "<<result -> data<<endl;
    else
        cout<<"K is larger than the length of the list.\n";
}