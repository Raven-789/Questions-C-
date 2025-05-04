#include<iostream>
using namespace std;

//Define node structure
struct Node{
    int data ;
    Node *next;

//constructor
Node(int val){
    data=val;
    next=nullptr;
    }
};

//Function to insert at head
Node* insertAtHead(Node* head,int val){
    Node* newNode=new Node(val); //create new node
    newNode->next=head;  //point to the old head
    return  newNode; //return new head
}

//Insert at the end
void insertAtEnd(Node *& head,int val){
    Node* newNode=new Node(val);
    newNode->data=val;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
        return;   
    }

    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
}

//Funtion to display linked list

void displayList(Node* head){
    while(head !=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"Null\n";
}

//Delete the first element
Node* deleteAtHead(Node * head){
    if(!head) return nullptr;
    Node * temp =head;
    head=head->next;
    delete temp;
    return head;
}

//Delete a node by val
void deleteNode(Node *& head ,int key){
    if(head==NULL){
        cout<<"List is empty.\n";
        return;
    }

    if(head->data==key){
        Node *temp=head;
        head=head ->next;
        delete temp;
        
        cout<<"Node with value "<<key<<" deleted.\n";
        return;
    }

    Node *curr=head;
    while(curr->next !=NULL && curr->next->data!=key)
        curr=curr->next;

    if(curr->next==NULL){
        cout<<"Value not found.\n";
        return;
    }

    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    cout<<"Node with value "<<key<<" deleted.\n";
}



 

//Driver code
int main(){
    Node* head=nullptr; //empty list

    head=insertAtHead(head,30);
    head=insertAtHead(head,20);
    head=insertAtHead(head,10);

    // cout<<"Singly Linked List: ";
    // displayList(head);

    // head=deleteAtHead(head);

    // cout<<"Singly Linked List: ";
    // displayList(head);

    insertAtEnd(head,70);
    displayList(head);

    deleteNode(head,0);
    displayList(head);
}