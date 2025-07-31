#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        //constructor
        Node(int d){
            this -> next = NULL;
            
            this -> data = d;
        }

        //Destructor Read his code could be useful
        ////will only be called explicitly as its dynamic allocation use delete "keyword"
        ~Node() {
        int val = this -> data;
        if(next != NULL) {
            // delete next;// don't use this line as this deletes all of the list
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

//Travesal

void print(Node * head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"Null"<<endl;
}

void printRev(Node *&tail){
    Node *tempp = tail;

    while(tempp != NULL){
        cout<<tempp -> data <<" -> ";
        tempp = tempp -> prev;
    }
    cout<<"Null"<<endl;
}



//Length of Linked list

int getLen(Node *head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

//Insert at start

void insertAtHead(Node * &head,Node *& tail, int data ){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp -> next = NULL;    // put these or else you won't be able to traverse backward in DLL as ptrs 
        temp -> prev = NULL;    // will be corroupted and there will be segmentation fault
    }else{
    Node* h = head;
        temp -> next = head;
        head -> prev = temp;
        temp -> prev = NULL;
        head = temp;
    }
}

//Insert at end
void insertAtTail(Node * &tail,Node*& head,int data){ // You forgot to use Ref. operator with tail okk...
    Node* temp = new Node(data);    //You made it better
    if(tail == NULL){
        tail = temp;
        head = temp;
        temp -> next = NULL;    // put these or else you won't be able to traverse backward in DLL as ptrs 
        temp -> prev = NULL;    // will be corroupted and there will be segmentation fault it was error in insert at head and tail functions
    }else{
        Node* t = tail;
        tail -> next = temp;
        temp ->prev = tail ;
        temp -> next = NULL;
        tail = temp;
    }

}

//Insert at any position

void insertAtPosition(Node *&h,Node * &tail, int k, int data){
    
    Node*temp = new Node(data);
    Node*s = h;
    bool chk = 1;
    int key = 1;

    if(k == 1){
        insertAtHead(h,tail, data);
        return;
    }

    while(s != NULL || k-1  == key || chk){
        if(key == k-1){
            if(s -> next == NULL){   // if we insert at last pos. we need to update tail too we did it here
                insertAtTail(tail, h, data);
                return;
            }else{
                temp -> next = s -> next ;
                s -> next = temp;
                temp -> prev = s;   // temp's prev element pointing back at s
                s -> next -> prev = temp; // start's next element pointing back to temp
                chk = 0;
                }
        }
        s = s -> next;
        key++;
    }
}


//Deletion----------------------------------------------------------------------------------------------------------------


//You've not freed any memory okay
void deleteMiddle(int pos, Node * &head, Node * & tail){
    
    Node *h = head;
    int cnt = 1;

    if(pos == 1){
        Node * temp = head;
        head -> next -> prev = NULL; //for the head's next element which is still pointing to the old head 
        head = head ->next ;
        free(temp);
        return;
    }

    while(cnt < pos-1 ){ // its finishing at 3 cause' remember loops always run +1 the max so its 2+1 =3 times ok
        h = h -> next;
        cnt++;
    }


    if ( h -> next->next == NULL){ //  Last node of the list

        h -> next -> prev = NULL;// this is only for DLL for single this doesn't need to be written
        h -> next = NULL;
        tail = h;

    }else{
        h -> next -> prev = NULL;
        h -> next = h -> next -> next;
    }


}



int main(){
    Node *node1 = new Node(10); //This won't be part of the list as we've initilaized head & tail as NULL and not 10
                                //and we also haven't used any of the insert functions
    Node *head = NULL;
    Node *tail = NULL;

    // insertAtTail(tail,head,5);
    // insertAtHead(head,tail,4);
    print(head);
    cout<<getLen(head)<<endl;
    insertAtHead(head,tail,0);
    insertAtHead(head,tail,9);
    print(head);
    cout<<getLen(head)<<endl;
    insertAtTail(tail,head,7);
    print(head);
    insertAtPosition(head,tail,3,6);
    print(head);
    printRev(tail); // YOU MADE A MISTAKE HERE BY NOT ASSIGNING NULL to ptrs in insertHead and inserttail function okk
    cout<<head -> data<<" "<< tail -> data<<endl;

    deleteMiddle(4,head,tail);
    print(head);
    // printRev(tail);

    cout<<head -> data<<" "<< tail -> data;
    // 1:13:57
}

























//His code yours is BETTER---------------------------------------------------------------------------------------------------------------------------------------------------


// #include<iostream>
// using namespace std;

// class Node {
//     public:
//     int data;
//     Node* prev;
//     Node* next;

//     //constructor
//     Node(int d ) {
//         this-> data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }

//     ~Node() {
//         int val = this -> data;
//         if(next != NULL) {
//             delete next;
//             next = NULL;
//         }
//         cout << "memory free for node with data "<< val << endl;
//     }
// };

// //traversing a linked list
// void print(Node* head) {
//     Node* temp  = head ;

//     while(temp != NULL) {
//         cout << temp -> data << " ";
//         temp  = temp -> next;
//     }
//     cout << endl;
// }

// //gives length of Linked List
// int getLength(Node* head) {
//     int len = 0;
//     Node* temp  = head ;

//     while(temp != NULL) {
//         len++;
//         temp  = temp -> next;
//     }

//     return len;
// }
// void insertAtHead(Node* &tail, Node* &head, int d) {

//     //empty list
//     if(head == NULL) {
//         Node* temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else{
//         Node* temp = new Node(d);
//         temp -> next = head;
//         head -> prev = temp;
//         head = temp;
//     }

// }


// void insertAtTail(Node* &tail,Node* &head, int d) {
//     if(tail == NULL) {
//         Node* temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else{
//         Node* temp = new Node(d);
//         tail -> next  = temp;
//         temp -> prev = tail;
//         tail = temp;
//     }

// }

// void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
//     //insert at Start
//     if(position == 1) {
//         insertAtHead(tail,head, d);
//         return;
//     }

//     Node* temp  = head;
//     int cnt = 1;

//     while(cnt < position-1) {
//         temp = temp->next;
//         cnt++;
//     }

//     //inserting at Last Position
//     if(temp -> next == NULL) {
//         insertAtTail(tail,head,d);
//         return ;
//     }

//     //creating a node for d
//     Node* nodeToInsert = new Node(d);

//     nodeToInsert ->next = temp -> next;
//     temp -> next -> prev = nodeToInsert;
//     temp -> next = nodeToInsert;
//     nodeToInsert -> prev = temp;
// }

// void deleteNode(int position, Node* & head) { 

//     //deleting first or start node
//     if(position == 1) {
//         Node* temp = head;
//         temp -> next -> prev = NULL;
//         head = temp ->next;
//         temp -> next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //deleting any middle node or last node
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }

//         curr -> prev = NULL;
//         prev -> next = curr -> next;
//         curr -> next = NULL;

//         delete curr;

//     }
// }



// int main() {


//     Node* head = NULL;
//     Node* tail = NULL;

//     print(head);
//     //cout << getLength(head) << endl;

//     insertAtHead(tail,head, 11);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtHead(tail,head, 13);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtHead(tail,head, 8);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtTail(tail,head, 25);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtPosition(tail, head, 2, 100);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtPosition(tail, head, 1, 101);
//     print(head);

//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     insertAtPosition(tail, head, 7, 102);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;

//     deleteNode(7, head);
//     print(head);
//     cout << "head  " << head -> data << endl;
//     cout << "tail  " << tail -> data << endl;





//     return 0;
// }