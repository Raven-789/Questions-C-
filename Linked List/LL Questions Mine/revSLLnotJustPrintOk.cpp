#include<iostream>
using namespace std;

// TIME COMPLEXITY OF ALL IS O(n)
// Space Complexity of all is also O(n)
// hw do rev in doubly linked list which you've alraedy done see it in DDL file you've print the DDL in rev using prev ptr okay 

class Node{
    public:
        int data;
        Node *next;

        //constructor
        Node(int d){
            this -> next = NULL;
            this -> data = d;
        }
        
        //Destructor
        ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            this->next = NULL;
            // delete this;// don't use this line as this deletes all of the list
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

//  Interative process ------------------------------------------------------------------------------------------------

Node* revSLL(Node * & head ){
    Node * curr = head, * prev = NULL, *fwd = NULL;
    
    while(curr != NULL){
        fwd = curr -> next;
        curr -> next = prev; // connecting it to previous node here. You made a mistake here prev = curr -> next
        prev = curr;
        curr = fwd;
    }

    return prev;

}

//------------------------------------------------------------------------------------------------------------------------------------------------
// Recursive Approach MINEEE  I also used default arguments YAYYYYYYYYYY!!!!

Node * revSLLRec( Node * curr, Node * fwd = NULL, Node * prev = NULL){

    // curr = head;

    if(curr == NULL){
        return prev;
    }

    fwd = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = fwd;

    revSLLRec(curr, fwd, prev);

}

//Recursive Approach HIS it BETTERR??!?!??!? he's using backtracking too damnnn
// void revSLLRec( Node * &head, Node * curr , Node * prev ){

//     // curr = head;

//     if(curr == NULL){
//         head = prev;
//         return;
//     }

//     Node* fwd = curr -> next;

//     revSLLRec(head, fwd, curr);

//     curr -> next = prev;

// }

//His 2nd Approach GODLYYYY!!!!!!!!!!!!!!!!!!!!!!!! its using backtracking extensively

Node * revSLLRec2nd(Node * head){

    //base case
    if(head == NULL || head -> next ==NULL){
        return head;
    }

    Node * chotaHead = revSLLRec2nd(head -> next);

    head -> next -> next = head;// this connecting every element to its prev node one by one
    head -> next = NULL;

    return chotaHead;

}

//------------------------------------------------------------------------------------------------------------------------------------------------

void print(Node * h){
    Node * temp = h;
    while(temp != NULL){
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(Node *& h, int data){

    Node *n = new Node(data);
    n -> next = h;
    h = n;
    
}

int main(){

    Node *n1 = new Node(1);
    Node *head = n1;
    // Node *head = NULL;// for testing of empty list 
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    print(head);
    // print( revSLL(head));   // comment one of the rev functions as both won't work


    // print(revSLLRec(head));  // my function's rec call

    // revSLLRec(head, head, NULL);// his function call
    // print(head);
    
    print(revSLLRec2nd(head));// his 2nd functions call GODLYY
    
    
}