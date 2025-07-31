#include<iostream>
using namespace std;

//You haven't done this with DDL don't trust the class you're seeing trust me you've not so as they both
//are similar soo just master this one 

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        //constructor
        Node(int d){
            this -> next = this;
            this -> data = d;
        }

        //Destructor
        //will only be called explicitly as its dynamic allocation use delete "keyword"
        ~Node() {
        int val = this -> data;
        if(next != NULL) {
            // delete next;// don't use this line as this deletes all of the list
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void insertNode(Node * &tail, int element, int val){
    //assuming that the element is IN the list

    Node * temp = new Node(val); //new node will be created in both scenarios in this function soo its your optimization

    //Empty List
    if(tail == NULL){
        tail = temp;
        temp -> next = tail; // pointing towards itself you can also write "temp" there too instead of "tail"
    }
    else{
        //Non empty list
        //assuming that the element is IN the list

        Node * t = tail;
        while(t -> data != element){
            t = t -> next;
        }

        //element found
        temp -> next = t -> next;// first connecting the next to positioned(the one which was given in argument) element 
        t -> next = temp;// secondly we're NOT connecting the positioned element we're connecting last element
                            // with NOT A new node but ITSELF here... you made a MISTAKE HERE


    }

}

//Deletion----------------------------------------------------------------------------------------------------------------------------

//2 POINTER APPROACH USED...

void deletion(Node * & tail,int val){

    //if List empty
    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    else{
        //Not Empty
        //assuming the val is present in the list
        Node* prev = tail , * curr = prev -> next;

        while(curr -> data != val){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // --------------------------------------------------------------------------------------------------------------------------------------------
        //these 2 conditions are for printing as if you don't do them you'll delete elements but 
        // won't be able to print them

        //for 1 node
        if(prev == curr){ // if both curr and prev are same then there's only 1 element by logic think on it if you don't get it right away
            tail = NULL;
        }
        // for > 2 nodes
        else if(tail == curr){
            tail = prev;
        }
        
        // -----------------------------------------------------------------------------------------------------------------------------------------------

        curr -> next = NULL;// curr dpends upon prev so when the function is called again its re-initialized with prev -> next 
        delete curr; //Explicitly calling destructors as its Dynamic Allocation


    }

}



// Traversal---------------------------------------------------------------------------------------------------------------------------

void print(Node *& tail){

    Node * temp = tail;

    if(tail == NULL){
        cout<<"List is Empty."<<endl;
    }

    do{
        cout<< temp -> data <<" -> ";
        temp = temp -> next ;
    }while(tail != temp);
    cout<<"Repeats..."<<endl;

}

int main(){

    Node *tail = NULL;

    //empty list insert 
    // you can put any element if its the 1st node of CLL as it won't matter 
    // cause' insert will run once for sure as its do while
    insertNode(tail, 5, 3);
    // print (tail);

    insertNode(tail,3,7);
    insertNode(tail,7,10);
    insertNode(tail,10,1);
    insertNode(tail,1,15);
    insertNode(tail,15,11);
    insertNode(tail,11,17);
    print(tail);
    deletion(tail,17);
    print(tail);

}