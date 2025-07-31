#include<iostream>
using namespace std;

// TIME Complexity O(n)
// Space Complexity O(n)


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

// class Node{
//     public:
//         int data;
//         Node *next;
//         Node *prev;

//         //constructor
//         Node(int d){
//             this -> next = this;
//             this -> data = d;
            
//         }

//         //Destructor
//         //will only be called explicitly as its dynamic allocation use delete "keyword"
//         ~Node() {
//         int val = this -> data;
//         if(next != NULL) {
//             delete next;
//             next = NULL;
//         }
//         cout << "memory free for node with data "<< val << endl;
//     }
// };


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

//My approach----------------------------------------------------------------------------------------------------------------------------------
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

// his approach -----------------------------------------------------------------------------------------------------------------------------------
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

int main(){
    Node * n1 = new Node(4);
    Node * tail = n1;
    // Node * tail = NULL;// for checking how function will do if list is empty 

    print(tail);

    insertNode(tail,4,8);
    insertNode(tail,8,3);
    insertNode(tail,3,7);
    insertNode(tail,7,9);
    insertNode(tail,9,1);
    print(tail);

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
}