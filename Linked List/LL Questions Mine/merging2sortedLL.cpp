#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data =val;
            next=nullptr;
        }
};

Node *mergeTwoLists(Node *l1, Node *l2){
    Node *dummy = new Node(-1);
    Node *tail=dummy;

    while(l1 != nullptr && l2!=nullptr){
        if(l1->data <l2->data){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail ->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }

    if(l1!=nullptr) tail ->next =l1;
    else tail->next =l2;

    return dummy->next;
}

void printList(Node * head){
    while(head != nullptr){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"Null\n";
}

int main(){
    //List 1: 1->3->5
    Node *l1=new Node(1);
    l1->next=new Node(2);
    l1->next=new Node(5);
    // printList(l1);

    //List 2: 2->4->6
    Node *l2=new Node(2);
    l2->next=new Node(4);
    l2->next=new Node(6);

    Node *merged=mergeTwoLists(l1,l2);
    cout<<"Merged Sorted List: ";
    printList(merged);

}