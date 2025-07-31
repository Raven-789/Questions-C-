#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this -> next = NULL;
            this -> data = data;
        }
        //Destructors will only be called explicitly as its dynamic allocation use delete "keyword"
};

//INSERTION 3 WAYS--------------------------------------------------------------------------------------------------------


//You've not freed any memory they're still there ok
void insertAtHead(Node *& h, int data){

    Node *n = new Node(data);
    n -> next = h;
    h = n;
    
}

void insertAtTail(Node * & t, int data){
    Node *temp = new Node(data);
    t -> next = temp;
    temp -> next =NULL;
    t = temp;
}

void insertAtMiddle(Node *&h,Node * &tail, int k, int data){
    Node*temp = new Node(data);
    Node*s = h;
    bool chk = 1;
    int key = 1;

    if(k == 1){
        insertAtHead(tail, data);
        return;
    }

    while(s != NULL || k-1  == key || chk){
        if(key == k-1){
            if(s -> next == NULL){   // if we insert at last pos. we need to update tail too we did it here
                insertAtTail(tail,data);
                return;
            }else{
                temp -> next = s -> next ;
                s -> next = temp;
                chk = 0;
                }
        }
        s = s -> next;
        key++;
    }
}


// DELETION-----------------------------------------------------------------------------------------------------------


// you didn't free the memory ok
void deleteMiddle(int pos, Node * &head, Node * & tail){
    
    Node *h = head;
    int cnt = 1;

    if(pos == 1){
        Node * temp = head;
        head = head ->next ;
        free(temp);
        return;
    }

    while(cnt < pos-1 ){ // its finishing at 3 cause' remember loops always run +1 the max so its 2+1 =3 times ok
        h = h -> next;
        cnt++;
    }


    if ( h -> next->next == NULL){ //  Last node of the list

        
        h -> next = NULL;
        tail = h;

    }else{
        h -> next = h -> next -> next;
    }


}

//Delete by val 

void deleteByVal (Node *head, int val){
    Node * temp = head;
    while(temp -> next -> data != val ){
        temp = temp ->next;
    }

    // if(temp -> next -> data == val){
            Node *del = temp -> next ;
            temp -> next = temp -> next -> next ;
            free(del);
        // }

}


// ------------------------------------------------------------------------------------------------------------------------
void print(Node * h){
    Node * temp = h;

    if(temp == NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        while(temp != NULL){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
}

//My approach
bool isCircular(Node * tail){
    Node * start = tail;

    //if list is empty
    if(tail == NULL){
        return true;
    }

    //if list is not empty
    while(tail != NULL){
        tail = tail -> next;
        if(tail == start){
            return true;
        }
    }

    return false;
}


// His appraoch
bool isCircularList(Node *tail){
    //empty
    if(tail == NULL){
        return true;
    }

    Node * temp = tail -> next;
    while(temp != NULL && temp != tail){
        temp = temp -> next;
    }

    if(temp == tail){
        return true;
    }

    return false;
}

int main(){
    Node *n1 = new Node(7);
    cout<<n1 -> data<<endl;
    cout<<n1 -> next<<endl;

    Node *tail = n1;
    Node *head = n1;

    // Node *tail = NULL; //for empty list conditoin check 
    // Node *head = NULL; //for empty list conditoin check 

    print(head); //for single node condtion check of isCircular

    insertAtHead(head,4);
    insertAtTail(tail,8);
    print(head);
    insertAtMiddle(head, tail, 2, 9);
    print(head);
    deleteMiddle(4,head,tail);
    print(head);

    if( isCircular(tail) ){
        cout<< "Circular"<<endl;
    }else{
        cout<< "Not Circular"<<endl;
    }
    
    if( isCircularList(tail) ){
        cout<< "Circular"<<endl;
    }else{
        cout<< "Not Circular"<<endl;
    }

    // deleteByVal(head,7);
    // print(head);
    cout<<head->data<<" " <<tail->data;
}

// Advantages of Linked list 
// Dynamic Size
// Easier insertion/deltetion
// 
// 























//HIS WAYS THIS time I did better yesssssssssss




// #include<iostream>
// #include<map>
// using namespace std;

// class Node {

//     public:
//     int data;
//     Node* next;

//     //constructor
//     Node(int data) {
//         this -> data = data;
//         this -> next = NULL;
//     }

//     //destructor
//     ~Node() {
//         int value = this -> data;
//         //memory free
//         if(this->next != NULL) {
//             delete next;// don't use this line as this deletes all of the list
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }

// };

// void insertAtHead(Node* &head, int d) {

//     // new node create
//     Node* temp = new Node(d);
//     temp -> next = head;
//     head = temp;
// }

// void insertAtTail(Node* &tail, int d) {
//      // new node create
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     tail  = temp;
// }

// void print(Node* &head) {

//     if(head == NULL) {
//         cout << "List is empty "<< endl;
//         return ;
//     }
//     Node* temp = head;

//     while(temp != NULL ) {
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


//     //insert at Start
//     if(position == 1) {
//         insertAtHead(head, d);
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
//         insertAtTail(tail,d);
//         return ;
//     }

//     //creating a node for d
//     Node* nodeToInsert = new Node(d);

//     nodeToInsert -> next = temp -> next;

//     temp -> next = nodeToInsert;
// }

// void deleteNode(int position, Node* & head) { 

//     //deleting first or start node
//     if(position == 1) {
//         Node* temp = head;
//         head = head -> next;
//         //memory free start ndoe
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

//         prev -> next = curr -> next;
//         curr -> next  = NULL;
//         delete curr;

//     }
// }

// int main() {
    
//     //created a new node
//     Node* node1 = new Node(10);
//     //cout << node1 -> data << endl;
//    // cout << node1 -> next << endl;
    
//     //head pointed to node1
//     Node* head = node1; 
//     Node* tail = node1;
//     //print(head);

//     insertAtTail(tail, 12);

//     //print(head);
    
//     insertAtTail(tail, 15);
//     //print(head);

//     insertAtPosition(tail,head, 4, 22);
//     //print(head);    

//     //cout << "head " << head -> data << endl;
//     //cout << "tail " << tail -> data << endl;

//     //deleteNode(4, head);
    

//     tail -> next = head ->next;

//     cout << "head " << head -> data << endl;
//     cout << "tail " << tail -> data << endl;
//     //print(head);

// }